#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
#pragma once

#include "Assignment.hpp"

namespace SDMS 
{

  class Scheduler
  {
    public:
      bool setPriority(Assignment assignment) const;
  };
}
#endif
