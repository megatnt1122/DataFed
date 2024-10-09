#ifndef DRIVER_HPP
#define DRIVER_HPP
#pragma once

namespace SDMS 
{
  enum class DRIVER_TYPE
  {
    SCHED_DRIVER,
    EXEC_DRIVER
  };

  class Driver
  {
    public: 
      virtual const DRIVER_TYPE getType() const = 0;
      virtual bool run() const = 0;
  };

}
#endif // DRIVER_HPP
