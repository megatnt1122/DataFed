#include "common/Manager.hpp"
#include "common/Assignment.hpp"
#include <iostream>
#include <vector>
#include <mutex>

namespace SDMS
{  
  std::vector<Assignment> Manager::popAssignments() 
  {
    myFavoriteManagerMutex.lock();
    std::vector<Assignment> returnVector = std::move(assignments);
    assignments.clear();
    myFavoriteManagerMutex.unlock();
    return returnVector; 
  }
  
  void Manager::addAssignment(Assignment&& assignment)
  {
    std::lock_guard<std::mutex> lock(myFavoriteManagerMutex);
	  assignments.push_back(std::move(assignment));
  }

  int Manager::sizeAssignments() const
  {
    std::lock_guard<std::mutex> lock(myFavoriteManagerMutex);
	  return assignments.size();
  }

}
