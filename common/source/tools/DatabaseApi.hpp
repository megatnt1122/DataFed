#ifndef DATABASEAPI_HPP
#define DATABASEAPI_HPP
#pragma once

#include "common/Tools.hpp"

namespace SDMS 
{
  class DatabaseApi : public Tool
  {
    public:
      DatabaseApi() = default;
      ~DatabaseApi()  = default;
      ToolType getType() const override;
      void Use() override;
  };
}

#endif
