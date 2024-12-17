#include "common/ToolFactory.hpp"
#include "common/Tools.hpp"
#include "tools/GlobusApi.hpp"
#include "tools/DatabaseApi.hpp"
#include <memory>

namespace SDMS 
{
  std::shared_ptr<Tool> ToolFactory::create(const ToolType toolType) const
  {
    if(toolType == ToolType::DatabaseApi)
    {
      //Put the options in here
      return std::make_shared<DatabaseApi>();
    }
    return nullptr;
  }
}
