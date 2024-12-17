#include "common/Assignment.hpp"

#include <memory>
#include <iostream>
#include <vector>

namespace SDMS 
{ 

    const std::vector<Skills>& Assignment::getSkills() const
    {
      return _skills;
    }

    std::vector<Skills> Assignment::getSkills()
    {
      return _skills;
    }

    const std::vector<ToolType>& Assignment::getToolTypes() const
    {
      return _toolTypes;
    }
    
    const Priority& Assignment::getPriority() const
    {
      return _priority;
    }

    const int& Assignment::getId() const
    {
      return _Id;
    }

    void Assignment::setState(AssignmentState newState)
    {
      assignmentState = newState;
    }

    AssignmentState Assignment::getState() const
    {
      return assignmentState;
    }
}
