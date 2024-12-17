#ifndef MANAGER_HPP
#define MANAGER_HPP
#pragma once

#include <vector>
#include"Assignment.hpp"
#include <mutex>

namespace SDMS
{

  class Manager
  {
    mutable std::mutex myFavoriteManagerMutex;
    public:
      //make this return the assignment type
      std::vector<Assignment> popAssignments();
	  // Add functions to manage assignments
      void addAssignment(Assignment&& assignment);
      int sizeAssignments() const;
    private:
        std::vector<Assignment> assignments; // Vector to hold Assignment objects
  };
}
#endif
