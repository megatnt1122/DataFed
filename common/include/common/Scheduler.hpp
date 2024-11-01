#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
#pragma once

#include "Assignment.hpp"
#include "Priority.hpp"
#include <vector>

namespace SDMS 
{

  class Scheduler
  {
   
    std::vector<std::pair<int,Priority>> _internalList;
    std::vector<Assignment> _internalAssignmentList;


  public:
    void addAssignment(Assignment assignment);
  

  };
}
#endif

//Notes:
//  Do I situate this so that it i
