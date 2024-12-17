#include "common/driver.hpp"
#include "SchedDriver.hpp"
#include "common/ComplianceOfficer.hpp"
#include "common/Manager.hpp"
#include "common/Scheduler.hpp"
#include "common/Assignment.hpp"
#include <boost/circular_buffer.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <memory>
#include <chrono>

namespace SDMS
{
  SchedDriver::~SchedDriver()
  {
      if(m_thread.joinable())
      {
        m_thread.join();
      }
  }

  SchedDriver::SchedDriver(std::shared_ptr<Scheduler> external_scheduler, bool runThreadOnCreation)
  {
    internal_scheduler = external_scheduler;
    keep_running.store(true);
    std::cout << keep_running << std::endl;
    if(runThreadOnCreation)
    {
      m_thread = std::thread(&SchedDriver::run, this);
    }
  }

  const DRIVER_TYPE SchedDriver::getType() const 
  {
    return DRIVER_TYPE::SCHED_DRIVER;
  }
    
  void SchedDriver::run() 
  {
    std::cout << "Entered run" << std::endl;
    //This is where the main scheduling running will happen
    //Initialize Everything:
    
    //Initialize
    boost::circular_buffer<Assignment> error_buffer(5);
    std::cout << "Passed error buffer" << std::endl;
    std::cout << keep_running.load() << std::endl; 
    while(keep_running.load())
    {
      std::cout << "Attempting to lock" << std::endl;
      myFavoriteDriverMutex.lock();
      std::cout << "Locking driver" << std::endl;
      int size = manager.sizeAssignments();
      std::cout << size << " = The size" << std::endl;
      std::vector<Assignment> assignments = manager.popAssignments();
      std::cout << "Unlocking driver" << std::endl;
      myFavoriteDriverMutex.unlock(); 

      //Check each assignment 
      for(Assignment& assignment : assignments)
      {
        std::cout << "We in" << std::endl;
        //Exit:
        if(assignment.getSkills().at(0) == Skills::EXIT)
        {

          std::cout << "Exitting" << std::endl;
          stop();
          break;
        }
        //If verification fails - Check for each assignment verification, NOT BATCHES
        if(complianceOfficer.verifyTask(assignment) == false)
          {

            std::cout << "Error but continuing" << std::endl;
            //Set the circular biffer
            error_buffer.push_back(std::move(assignment));
            
            //RETURN AN ERROR BUT CONTINUE ON NEXT Assignment
            continue;
            //Add mnore here for error handling etc
          }

        if(internal_scheduler)
        {
         
          //  Verification is for the message mapping within the code
          internal_scheduler->addAssignment(std::move(assignment)); //Maybe have assignment have apriority value?
        }
        else
        {
          //Throw an error
        }
      }
      //Exit if needed
      if(!keep_running.load())
      {
        break;
      }
      std::cout << "Is this thing on?" << std::endl; 
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
  }

  void SchedDriver::addManagerAssignment(Assignment&& assignment)
  {
    const std::lock_guard<std::mutex> lock(myFavoriteDriverMutex); 
    manager.addAssignment(std::move(assignment));
  }

     
  void SchedDriver::stop()
  {
    keep_running.store(false);
  }

}

//NOTES:
//  Scheduling Driver is the first to run, it recieves some tasks from an outer source
//    it then goes to the loop with a collection of assignments... we  will 
//    verify in the manager, we will then schedule the assignment's priority within
//    the internal list.

