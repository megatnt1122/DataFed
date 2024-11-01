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

    const std::vector<Tools>& Assignment::getTools() const
    {
      return _tools;
    }
    
    const Priority& Assignment::getPriority() const
    {
      return _priority;
    }

    const int& Assignment::getId() const
    {
      return _Id;
    }

}
