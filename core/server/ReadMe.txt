#THIS IS A TEST CONCEPT TO IMPLEMENT OVER GlobusAPI.cpp

#include "GlobusAPI.hpp"

namespace SDMS {
namespace Core {

// Private helper method for initializing CURL handle
void initCurlHandle(CURL *curl_handle) {
    curl_easy_setopt(curl_handle, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_1);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, curlResponseWriteCB);
    curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(curl_handle, CURLOPT_TCP_NODELAY, 1);
}

// Private helper method to build URL with parameters
std::string buildUrl(const std::string &base_url, const std::string &url_path,
                     const std::vector<std::pair<std::string, std::string>> &params) {
    std::string url = base_url + url_path;
    char *esc_txt;

    for (auto &param : params) {
        if (param == params.front()) {
            url.append("?");
        } else {
            url.append("&");
        }

        url.append(param.first);
        url.append("=");
        esc_txt = curl_easy_escape(nullptr, param.second.c_str(), 0);
        url.append(esc_txt);
        curl_free(esc_txt);
    }

    return url;
}

GlobusAPI::GlobusAPI() : m_config(Config::getInstance()) {
    init();
}

GlobusAPI::GlobusAPI(LogContext log_context)
    : m_config(Config::getInstance()), m_log_context(log_context) {
    init();
}

void GlobusAPI::init() {
    m_curl_xfr = curl_easy_init();
    if (!m_curl_xfr)
        EXCEPT(1, "libcurl init failed");
    initCurlHandle(m_curl_xfr);

    m_curl_auth = curl_easy_init();
    if (!m_curl_auth)
        EXCEPT(1, "libcurl init failed");
    initCurlHandle(m_curl_auth);
}

GlobusAPI &GlobusAPI::operator=(GlobusAPI &&other) noexcept {
    if (this != &other) {
        this->m_curl_xfr = other.m_curl_xfr;
        this->m_curl_auth = other.m_curl_auth;
        this->m_log_context = other.m_log_context;
    }
    return *this;
}

GlobusAPI::~GlobusAPI() {
    curl_easy_cleanup(m_curl_auth);
    curl_easy_cleanup(m_curl_xfr);
}

long GlobusAPI::performCurlRequest(CURL *curl_handle, const std::string &url,
                                   const std::string &token,
                                   const std::vector<std::pair<std::string, std::string>> &params,
                                   const std::string &body, std::string &result) {
    char error[CURL_ERROR_SIZE];
    error[0] = 0;

    std::string full_url = buildUrl(url, "", params);

    curl_easy_setopt(curl_handle, CURLOPT_URL, full_url.c_str());
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &result);
    curl_easy_setopt(curl_handle, CURLOPT_ERRORBUFFER, error);

    if (!body.empty()) {
        curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, body.c_str());
    }

    struct curl_slist *list = nullptr;

    if (!token.empty()) {
        std::string auth_hdr = "Authorization: Bearer " + token;
        list = curl_slist_append(list, auth_hdr.c_str());
    } else {
        curl_easy_setopt(curl_handle, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
        curl_easy_setopt(curl_handle, CURLOPT_USERNAME, m_config.client_id.c_str());
        curl_easy_setopt(curl_handle, CURLOPT_PASSWORD, m_config.client_secret.c_str());
    }

    curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, list);

    CURLcode res = curl_easy_perform(curl_handle);

    if (list) {
        curl_slist_free_all(list);
    }

    long http_code = 0;
    curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &http_code);

    if (res != CURLE_OK) {
        DL_ERROR(m_log_context,
                 "CURL error [" << error << "], " << curl_easy_strerror(res));
        EXCEPT_PARAM(1, "Globus API call failed.");
    }

    return http_code;
}

long GlobusAPI::get(CURL *curl_handle, const std::string &base_url,
                    const std::string &url_path, const std::string &token,
                    const std::vector<std::pair<std::string, std::string>> &params,
                    std::string &result) {
    std::string full_url = buildUrl(base_url, url_path, params);
    return performCurlRequest(curl_handle, full_url, token, {}, "", result);
}

long GlobusAPI::post(CURL *curl_handle, const std::string &base_url,
                     const std::string &url_path, const std::string &token,
                     const std::vector<std::pair<std::string, std::string>> &params,
                     const std::string &body, std::string &result) {
    std::string full_url = buildUrl(base_url, url_path, params);
    return performCurlRequest(curl_handle, full_url, token, params, body, result);
}

std::string GlobusAPI::getSubmissionID(const std::string &acc_token) {
    std::string raw_result;
    long code = get(m_curl_xfr, m_config.glob_xfr_url, "submission_id",
                    acc_token, {}, raw_result);

    try {
        if (raw_result.empty())
            EXCEPT_PARAM(ID_SERVICE_ERROR, "Empty response. Code: " << code);

        Value result;
        result.fromString(raw_result);

        Value::Object &resp_obj = result.asObject();

        checkResponseCode(code, resp_obj);

        return resp_obj.getString("value");
    } catch (libjson::ParseError &e) {
        DL_DEBUG(m_log_context, "PARSE FAILED! " << raw_result);
        EXCEPT_PARAM(ID_SERVICE_ERROR,
                     "Globus submission API call returned invalid JSON.");
    } catch (TraceException &e) {
        DL_DEBUG(m_log_context, raw_result);
        e.addContext("Globus submission API call failed.");
        throw;
    } catch (...) {
        DL_DEBUG(m_log_context, "UNEXPECTED/MISSING JSON! " << raw_result);
        EXCEPT_PARAM(ID_SERVICE_ERROR,
                     "Globus submission API call returned unexpected content");
    }
}

std::string GlobusAPI::transfer(const std::string &src_ep, const std::string &dst_ep,
                                const std::vector<std::pair<std::string, std::string>> &files,
                                bool encrypt, const std::string &acc_token) {
    std::string sub_id = getSubmissionID(acc_token);

    Value body;
    Value::Object &obj = body.initObject();
    obj["DATA_TYPE"] = "transfer";
    obj["submission_id"] = sub_id;
    obj["source_endpoint"] = src_ep;
    obj["destination_endpoint"] = dst_ep;
    obj["verify_checksum"] = true;
    obj["notify_on_succeeded"] = false;
    obj["encrypt_data"] = encrypt;

    Value::Array &xfr_list = obj["DATA"].initArray();
    xfr_list.reserve(files.size());

    for (auto &file : files) {
        Value xfr_item;
        Value::Object &xobj = xfr_item.initObject();
        xobj["DATA_TYPE"] = "transfer_item";
        xobj["source_path"] = file.first;
        xobj["destination_path"] = file.second;
        xobj["recursive"] = false;
        xfr_list.push_back(std::move(xfr_item));
    }

    std::string raw_result;
    long code = post(m_curl_xfr, m_config.glob_xfr_url, "transfer",
                     acc_token, {}, body.toString(), raw_result);

    try {
        if (raw_result.empty())
            EXCEPT_PARAM(ID_SERVICE_ERROR, "Empty response. Code: " << code);

        Value result;
        result.fromString(raw_result);

        Value::Object &resp_obj = result.asObject();

        checkResponseCode(code, resp_obj);

        std::string &task_id = resp_obj.getString("task_id");
        return task_id;
    } catch (libjson::ParseError &e) {
        DL_ERROR(m_log_context, "PARSE FAILED! " << raw_result);
        EXCEPT_PARAM(ID_SERVICE_ERROR,
                     "Globus transfer API call returned invalid JSON.");
    } catch (TraceException &e) {
        DL_ERROR(m_log_context, raw_result);
        e.addContext("Globus transfer API call failed.");
        throw;
    } catch (...) {
        DL_ERROR(m_log_context, "UNEXPECTED EXCEPTION " << raw_result);
        EXCEPT_PARAM(ID_SERVICE_ERROR,
                     "Globus transfer API call returned unexpected content");
    }
}

bool GlobusAPI::checkTransferStatus(const std::string &task_id,
                                    const std::string &acc_token,
                                    XfrStatus &status,
                                    std::string &err_msg) {
    status = XS_INIT;
    err_msg.clear();
    std::string raw_result;

    long code = get(m_curl_xfr, m_config.glob_xfr_url, "task/" + task_id,
                    acc_token, {}, raw_result);

    try {
        if (raw_result.empty()) {
            EXCEPT_PARAM(ID
