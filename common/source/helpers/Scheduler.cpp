#include "common/Scheduler.hpp"
#include "common/Assignment.hpp"
#include <iostream>
#include <vector>

namespace SDMS
{ 

  //Needs to add it to an internal assignment vector
  void Scheduler::addAssignment(Assignment assignment) 
  {
    //Change this to be based off priority in some way
    _internalAssignmentList.push_back(assignment);

    return;
  }
}
