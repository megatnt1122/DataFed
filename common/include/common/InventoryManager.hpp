#ifndef INVENTORY_MANAGER_HPP
#define INVENTORY_MANAGER_HPP
#pragma once

#include "Assignment.hpp"

namespace SDMS 
{

  class InventoryManager
  {
    public:
      std::vector<std::shared_ptr<Tool>> getTools(Assignment& assignment); 
  };
}
#endif
