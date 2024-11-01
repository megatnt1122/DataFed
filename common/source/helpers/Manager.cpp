#include "common/Manager.hpp"
#include "common/Assignment.hpp"
#include <iostream>
#include <vector>

namespace SDMS
{  
  std::vector<Assignment> Manager::popAssignments() 
  {
    std::vector<Assignment> returnVector = std::move(assignments);
    assignments.clear();
    return std::move(returnVector); 
  }
  
  void Manager::addAssignment(Assignment&& assignment)
  {
	  assignments.push_back(std::move(assignment));
  }

  void Manager::printAssignments() const
  {
	  std::cout << "Number of assignments: " << assignments.size() << "\n";
  }

}
