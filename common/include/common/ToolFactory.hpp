#ifndef TOOL_FACTORY_HPP
#define TOOL_FACTORY_HPP
#pragma once

#include "Tools.hpp"
#include <memory>

namespace SDMS 
{
  class ToolFactory
  {
    public:
      std::shared_ptr<Tool> create(const ToolType toolType) const;
  };
}
#endif
