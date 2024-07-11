#ifndef HTTPCOMMUNICATOR_HPP
#define HTTPCOMMUNICATOR_HPP
#pragma once

//Fix the includes and 
#include "common/ICommunicator.hpp"
#include "common/IMessage.hpp"
#include "common/MessageFactory.hpp"
#include "common/DynaLog.hpp"

//Standard includes
#include <memory>
#include <string>

namespace SDMS{
//This talks to the
class HTTPCommunicator : public ICommunicator
{
protected:
  LogContext m_log_context;

public:
  
  explicit HTTPCommunicator(const LogContext &log_context) : m_log_context(log_context){};

  virtual Response poll(const MessageType) final;

  /**
      * This is technical debt in the future get rid of MsgBuf and replace with
      * IMessage
      **/
  virtual void send(IMessage &message) final;

  /* Ideally in the future get rid of MsgBuf and replace with IMessage
      **/
  virtual Response receive(const MessageType) final;

  virtual const std::string id() const noexcept final;
  virtual const std::string address() const noexcept final;

  virtual ~HTTPCommunicator(){};

};

}
#endif // HTTP_HP
