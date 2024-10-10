#include "common/ComplianceOfficer.hpp"
#include <iostream>

namespace SDMS 
{  
  bool ComplianceOfficer::verifyTask(bool assignment) const
  {
    if(assignment)
    {
      return true;
    }
    else 
    {
      return false;
    }    
  }
}
