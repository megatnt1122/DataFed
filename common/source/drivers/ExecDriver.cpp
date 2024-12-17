#include "common/driver.hpp"
#include "ExecDriver.hpp"
#include "common/StaffingCoordinator.hpp"
#include "common/InventoryManager.hpp"
#include "common/Manager.hpp"
#include "common/Worker.hpp"
#include <boost/circular_buffer.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <memory>
#include <chrono>


namespace SDMS 
{
  ExecDriver::~ExecDriver()
  {

      if(m_thread.joinable())
      {
        m_thread.join();
      }
    
  }

  ExecDriver::ExecDriver(std::shared_ptr<Scheduler> external_scheduler, bool runThreadOnCreation)
  {
    internal_scheduler = external_scheduler;
    keep_running.store(true);
    std::cout << keep_running << std::endl;
    if(runThreadOnCreation)
    {
      m_thread = std::thread(&ExecDriver::run, this);
    }
  }

  const DRIVER_TYPE ExecDriver::getType() const 
  {
    return DRIVER_TYPE::EXEC_DRIVER;
  }

  void ExecDriver::run() 
  {
    std::cout << "Entered run" << std::endl;
    //This is where the main scheduling running will happen
    //Initialize Everything:
    
    //Initialize
    boost::circular_buffer<Assignment> error_buffer(5);
    std::cout << "Passed error buffer" << std::endl;
    std::cout << keep_running.load() << std::endl; 
    Assignment assignment;
    while(keep_running.load())
    {
      std::cout << "Yoooo" << std::endl;
      std::cout << internal_scheduler->sizeAssignments() << std::endl;
      while(internal_scheduler->sizeAssignments() > 0 and !sc.reachedMaxWorkers())
      {
        std::cout << "Entering internal while" << std::endl;

        std::cout << "Attempting to lock" << std::endl;
        mySecondFavoriteDriverMutex.lock();
        std::cout << "Popping assignment" << std::endl;
        assignment = internal_scheduler->popAssignment();
        std::cout << "Unlocking" << std::endl;
        mySecondFavoriteDriverMutex.unlock();
        if(assignment.getSkills().at(0) == Skills::EXIT)
        {
      
          std::cout << "Exitting" << std::endl;
          stop();
          break;
        }
        std::cout << "Midpoint" << std::endl;
        std::cout << internal_scheduler->sizeAssignments() << std::endl;
        //Hiring worker based off assignment | Maybe give the assignment to the worker - perhaps worker has a skill attached for below
        Worker& worker = sc.hireWorker(assignment);
        std::cout << "After hiring a worker" << std::endl;
        std::cout << internal_scheduler->sizeAssignments() << std::endl;
        
        //Get appropriate tools | assignment and worker would be used to dictate appropriate tools
        std::vector<std::shared_ptr<Tool>> tools = im.getTools(assignment);
        //Worker uses tools to do work 
        
        worker.execute(std::move(assignment), tools); //this execute would have a while within
        //
        //manager.updateAssignment(std::move(assignment));
        //
        //sc.reassignWorker(worker)
        //
        
      }
      //Add for loop to check working workers statuses
      sc.checkWorkerStates();

      if(!keep_running.load())
      {
        break;
      }
      return;
    } 
  }


  void ExecDriver::stop()
  {
    keep_running.store(false);
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
