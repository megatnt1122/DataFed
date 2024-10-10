#ifndef EXECDRIVER_HPP
#define EXECDRIVER_HPP
#pragma once


#include "common/driver.hpp"

namespace SDMS 
{
  class ExecDriver : public Driver
  {
    public:
      const DRIVER_TYPE getType() const override;
      bool run() const override;
  };
}

#endif // SCHEDDRIV
