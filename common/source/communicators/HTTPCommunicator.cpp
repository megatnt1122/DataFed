//Local Private Includes
#include "HTTPCommunicator.hpp"

//Local Public Includes
#include "common/ICommunicator.hpp"
#include "common/IMessage.hpp"

//Standard includes
#include <memory>
#include <string>

namespace SDMS{
  
  ICommunicator::Response 
  HTTPCommunicator::poll(const MessageType){
    return ICommunicator::Response();
  }

  /**
      * This is technical debt in the future get rid of MsgBuf and replace with
      * IMessage
      **/
  void HTTPCommunicator::send(IMessage &message){
  }

  /* Ideally in the future get rid of MsgBuf and replace with IMessage
      **/
  ICommunicator::Response
  HTTPCommunicator::receive(const MessageType){
    return ICommunicator::Response();
  }

  const std::string HTTPCommunicator::id() const noexcept{
    return std::string("hello");
  }
  
  const std::string HTTPCommunicator::address() const noexcept{
    return std::string("hello");
  }
}
