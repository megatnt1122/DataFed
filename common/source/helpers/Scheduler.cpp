#include "common/Scheduler.hpp"
#include "common/Assignment.hpp"
#include <iostream>
#include <vector>
#include <mutex>

namespace SDMS
{ 

  //Needs to add it to an internal assignment vector
  void Scheduler::addAssignment(Assignment&& assignment) 
  {
    std::lock_guard<std::mutex> lock(myFavoriteMutex);
    //First In First Out
    if(m_sort_order == SchedulerOrder::FIFO)
    {
      //Change this to be based off priority in some way
      _internalAssignmentList.push_back(std::move(assignment));
      return;
    }

    if(m_sort_order == SchedulerOrder::PRIO)
    {
      return;
    }
  }
  Assignment Scheduler::popAssignment()
  {
    std::lock_guard<std::mutex> lock(myFavoriteMutex);
    if(m_sort_order == SchedulerOrder::FIFO)
    {
      Assignment returnAssignment = std::move(_internalAssignmentList.back());
      _internalAssignmentList.pop_back();
      return returnAssignment;
    }
  }

  int Scheduler::sizeAssignments() const
  {
    std::lock_guard<std::mutex> lock(myFavoriteMutex);
	  return _internalAssignmentList.size();
  }
}

//Notes:
//  We need to set it up with priority if statements too but right now we are only testing
//
//  Should the if statments have sort_order or m_sort_order
