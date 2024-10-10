#include "common/driver.hpp"
#include "ExecDriver.hpp"
#include "common/StaffingCoordinator.hpp"
#include "common/InventoryManager.hpp"
#include "common/Manager.hpp"
#include "common/Worker.hpp"
#include <iostream>

namespace SDMS 
{

  const DRIVER_TYPE ExecDriver::getType() const 
  {
    return DRIVER_TYPE::EXEC_DRIVER;
  }

  bool ExecDriver::run() const
  {
    
    StaffingCoordinator sc;
    InventoryManager im;
    Manager exec_manager;

    std::vector<Assignment> internalList;

    //Change this to check if theres another task avaliable
    while(true)
    {
      //NOTE
      auto assignment = sc.grabNextAssignment(internalList);

      //If assignment is to exit job site then exit loop
      //if(assignment == exit)
      if(true)
      {
        break;
      }
      
      //Hiring worker based off assignment | Maybe give the assignment to the worker - perhaps worker has a skill attached for below
      //worker = sc.hireWorker(assignment)
      //
      //Get appropriate tools | assignment and worker would be used to dictate appropriate tools
      //tools = im.getTools(worker.skill, assignment)
      //
      //Worker uses tools to do work 
      //assignment = worker.execute(assignment, tools) //this execute would have a while within
      //
      //manager.updateAssignment(assignment)
      //
      //sc.reassignWorker(worker)
      //
      return true;
    }  
  }
}

//NOTES:
//  So the Exec driver is executing the code the assignments, it hires the worker
//    gets the appropriate tools, does the work then updates the assignment and sends it
//    to the manager after it either finishes its work or runs out of time. Then we
//    reassign the worker to something afterwards.
//
//
//
