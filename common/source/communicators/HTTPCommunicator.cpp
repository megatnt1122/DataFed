//Local Private Includes
#include "HTTPCommunicator.hpp"


// Local public includes
#include "common/DynaLog.hpp"
#include "common/IMessage.hpp"
#include "common/ISocket.hpp"
#include "common/SocketFactory.hpp"
#include "common/SocketOptions.hpp"

//Standard includes
#include <memory>
#include <string>
#include <unordered_map>

namespace SDMS{



/******************************************************************************
 * Public Class Methods
 ******************************************************************************/

  //Created contructor for HTTPCommunicator
  HTTPCommunicator::HTTPCommunicator(const SocketOptions &socket_options,
                   const ICredentials &credentials,
                   uint32_t timeout_on_receive_milliseconds,
                   long timeout_on_poll_milliseconds,
                   const LogContext &log_context)
    : m_timeout_on_receive_milliseconds(timeout_on_receive_milliseconds),
      m_timeout_on_poll_milliseconds(timeout_on_poll_milliseconds){
    //Add the socket fact here
    m_log_context = log_context;
    auto socket_factory = SocketFactory();
    m_socket = socket_factory.create(socket_options, credentials);
    
    std::string id = m_socket->getID();
  if (id.size() > constants::communicator::MAX_COMMUNICATOR_IDENTITY_SIZE) {
    std::string error_msg = 
      "HTTP exceeds max number of characters allowed, allowed: ";
    error_msg +=
      std::to_string(constants::communicator::MAX_COMMUNICATOR_IDENTITY_SIZE);
    error_msg +=
        " number provided " + std::to_string(id.size()) + " identity: " + id;
    DL_ERROR(m_log_context, error_msg);
    //EXCEPT_PARAM(1, error_msg);
  }
}


  ICommunicator::Response 
  HTTPCommunicator::poll(const MessageType message_type){
    //Put send and recieve here and make sure response = response
    Response response = 
    LogContext log_context = m_log_context;
    if (response.error == false and response.time_out == false) {
      response.message = m_msg_factory.create(message_type); 
      log_context.correlation_id = std::get<std::string>(response.message->get(MessageAttribute::CORRELATION_ID));
      std::string err_message = "Received message on communicator id: " + id();
      err_message += ", receiving from address: " + address();
    } else {
        if (response.error) {
          std::string err_message =
              "Error encountered for communicator id: " + id();
          err_message +=
              ", error is: " + response.error_msg;
          err_message +=
              ", receiving from address: " + address();
          DL_ERROR(log_context, err_message);
        } else if (response.time_out) {
            std::string err_message =
                "Timeout encountered for communicator id: " + id();
            err_message +=
                ", timeout occurred after: " + m_timeout_on_poll_milliseconds;
            err_message += 
                ", receiving from address: " + address();
            DL_TRACE(log_context, err_message);
        }
  }
    return response;
  }

  /**
      * This is technical debt in the future get rid of MsgBuf and replace with
      * IMessage
      **/
  void HTTPCommunicator::send(IMessage &message){
  //add curl here
  //create a std list of type IComm::Response, to be our buffer that
  }

  /* Ideally in the future get rid of MsgBuf and replace with IMessage
      **/
  ICommunicator::Response
  HTTPCommunicator::receive(const MessageType){
  //FIFO from send's (imaginary) buffer
    return ICommunicator::Response();
  }

  const std::string HTTPCommunicator::id() const noexcept{
    return std::string("hello");
  }
  
  const std::string HTTPCommunicator::address() const noexcept{
    return std::string("hello");
  }
}
