#include "common/InventoryManager.hpp"
#include "common/ToolFactory.hpp"
#include "common/Assignment.hpp"
#include <iostream>

namespace SDMS 
{  
  //So the skill will be of a skill type and it comes from the worker when it is created
  std::vector<std::shared_ptr<Tool>> InventoryManager::getTools( Assignment& assignment)
  {
    std::vector<std::shared_ptr<Tool>> toolVector; 
    ToolFactory factory;
    for (ToolType tool : assignment.getToolTypes())
    { 
      toolVector.push_back(factory.create(tool));
      //Change this back to assignment once things get sorted
    }
    return toolVector;
  }
}
