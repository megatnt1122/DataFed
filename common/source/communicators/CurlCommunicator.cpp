// Local private includes
#include "CurlCommunicator.hpp"

namespace SDMS {
  
  CurlCommunicator::CurlCommunicator(const SocketOptions &socket_options,
                     const ICredentials &credentials,
                     uint32_t timeout_on_receive_milliseconds,
                     long timeout_on_poll_milliseconds,
                     const LogContext &log_context) {

  }

  CurlCommunicator::~CurlCommunicator() {

  }
  /**
   * Poll for incoming messages at the sockets
   *
   * Return true if a message(s) has been provided
   * Return false if timeout and or no message
   **/
  ICommunicator::Response CurlCommunicator::poll(const MessageType) {

  }

  void CurlCommunicator::send(IMessage &message) {

  }

  ICommunicator::Response CurlCommunicator::receive(const MessageType) {
  }

  const std::string CurlCommunicator::id() const {

  }
  const std::string CurlCommunicator::address() const {

  }

} // namespace SDMS

#endif // CURL_COMMUNICATOR_HPP
