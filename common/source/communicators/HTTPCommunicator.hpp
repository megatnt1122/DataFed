#ifndef HTTPCOMMUNICATOR_HPP
#define HTTPCOMMUNICATOR_HPP
#pragma once

//Fix the includes and 
#include "common/ICommunicator.hpp"

namespace my_examples 
{
//This talks to the
  class Http : public ICommunicator 
      public:
      const COMMUNICATOR_TYPE getType() const override;
      {
   //I think we need to have the send and recieve functions, I am confused on how I should go about reconfiguring send and recieve if so?
   //I understand that I need to throw the big GlobusAPI functions within the send and recieve,
  //
  //response Type and funcs are in Icomm header
  };
}
#endif // HTTP_HP
