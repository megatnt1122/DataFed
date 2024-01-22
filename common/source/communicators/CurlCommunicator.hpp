#ifndef CURL_COMMUNICATOR_HPP
#define CURL_COMMUNICATOR_HPP
#pragma once

// Local private includes
#include "../Buffer.hpp"

// Local public includes
#include "../ProtoBufFactory.hpp"
#include "common/DynaLog.hpp"
#include "common/ICommunicator.hpp"
#include "common/IMessage.hpp"
#include "common/ISocket.hpp"
#include "common/MessageFactory.hpp"

// Third party includes
#include <curl/curl.h>

// Standard includes
#include <memory>
#include <string>

namespace SDMS {

class CurlCommunicator : public ICommunicator {
protected:
  std::unique_ptr<ISocket> m_socket;

  /// Optional timeout in milliseconds (0 = wait forever)
  uint32_t m_timeout_on_receive_milliseconds = 0;
  long m_timeout_on_poll_milliseconds = 10;
  MessageFactory m_msg_factory;
  Buffer m_buffer;
  ProtoBufFactory m_protocol_factory;
  ICommunicator::Response m_poll(uint32_t timeout_milliseconds);

  LogContext m_log_context;

public:
  /** To be used by children*/
  CurlCommunicator(const LogContext &log_context)
      : m_log_context(log_context){};

  CurlCommunicator(const SocketOptions &socket_options,
                     const ICredentials &credentials,
                     uint32_t timeout_on_receive_milliseconds,
                     long timeout_on_poll_milliseconds,
                     const LogContext &log_context);

  virtual ~CurlCommunicator();
  /**
   * Poll for incoming messages at the sockets
   *
   * Return true if a message(s) has been provided
   * Return false if timeout and or no message
   **/
  virtual ICommunicator::Response poll(const MessageType) final;

  virtual void send(IMessage &message) final;
  virtual ICommunicator::Response receive(const MessageType) final;

  virtual const std::string id() const noexcept final;
  virtual const std::string address() const noexcept final;
};

} // namespace SDMS

#endif // CURL_COMMUNICATOR_HPP
