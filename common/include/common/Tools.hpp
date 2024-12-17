#ifndef TOOLS_HPP
#define TOOLS_HPP
#pragma once

namespace SDMS
{
  enum class ToolType{ GlobusApi,
                    DatabaseApi};

  class Tool
  {
    public:
      virtual ToolType getType() const = 0;
      virtual void Use() = 0;
  };
}
#endif
