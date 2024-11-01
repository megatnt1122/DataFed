#ifndef MANAGER_HPP
#define MANAGER_HPP
#pragma once

#include <vector>
#include"Assignment.hpp"

namespace SDMS
{

  class Manager
  {
    public:
      //make this return the assignment type
      std::vector<Assignment> popAssignments();
      
	  // Add functions to manage assignments
      void addAssignment(Assignment&& assignment);
      void printAssignments() const;
      
    private:
        std::vector<Assignment> assignments; // Vector to hold Assignment objects
  };
}
#endif
