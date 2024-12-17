#include "common/StaffingCoordinator.hpp"
#include "common/Assignment.hpp"
#include <iostream>
#include "common/Worker.hpp"
#include <vector>
#include <boost/circular_buffer.hpp>

namespace SDMS 
{  
  Worker& StaffingCoordinator::hireWorker(Assignment& assignment) 
  {
    numOfWorkers = numOfWorkers + 1;
    Worker returnWorker = Worker(assignment.getSkills());
    myFavoriteSCMutex.lock();
    //m_workers.emplace_back(new Worker(assignment.getSkills()));
    auto testSkills = assignment.getSkills(); 
    m_workers.emplace_back(std::move(testSkills));
    myFavoriteSCMutex.unlock();
    return m_workers.back();
  }

  bool StaffingCoordinator::reachedMaxWorkers()
  {
   if(numOfWorkers == 5)
   {
     return true;
   }
   else 
   {
     return false;
   }
  }
  
  void StaffingCoordinator::removeWorker()
  {
    numOfWorkers = numOfWorkers - 1;
  }

  /*void StaffingCoordinator::checkWorkerStates()
  {
    //First loop and check each worker state, copying those states into a circular buffer for debugging
    for(worker : m_workers)
    {
      std::cout << "Putting worker state into buffer"<< std::endl;
      state_buffer.push_back(worker.getState()); 
    }
  }
  */
}

//Notes:
//
//So we need to keep in mind that when hiring a worker we need to assign it a skill here based off the assignment, the inventory manager will handle tools, think of the skills as the class and the tools as the interface... so the skills is the drill and the tools are the drill bits
