#include "common/driver.hpp"
#include "SchedDriver.hpp"
#include "common/ComplianceOfficer.hpp"
#include "common/Manager.hpp"
#include "common/Scheduler.hpp"
#include "common/Assignment.hpp"
#include <iostream>
#include <vector>

namespace SDMS
{
  

  const DRIVER_TYPE SchedDriver::getType() const 
  {
    return DRIVER_TYPE::SCHED_DRIVER;
  }
  
  bool SchedDriver::run() const
  {
    //This is where the main scheduling running will happen
    //Initialize Everything:
    
    //Initialize
    auto CO = ComplianceOfficer();
    //
    auto sched_manager = Manager();
    auto scheduler = Scheduler();
    //This is from external list
    std::vector<Assignment> assignments = sched_manager.getAssignments();
    
    //
    for(Assignment& assignment : assignments)
    {
    //  Verification is for the message mapping within the code
    //  scheduler.setPriority(assignment)
    //  
    // 
    break;
    
    }
    return true;
  }
}

//NOTES:
//  Scheduling Driver is the first to run, it recieves some tasks from an outer source
//    it then goes to the loop with a collection of assignments... we  will 
//    verify in the manager, we will then schedule the assignment's priority within
//    the internal list.
//
//
//
//
