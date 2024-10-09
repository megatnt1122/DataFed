#ifndef DRIVER_FACTORY_HPP
#define DRIVER_FACTORY_HPP
#pragma once

#include "driver.hpp"
#include <memory>

namespace SDMS 
{
  class DriverFactory
  {
    public:
      std::unique_ptr<Driver> create(const DRIVER_TYPE) const;
  };
}
#endif
