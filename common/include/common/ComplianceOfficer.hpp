#ifndef COMPLIANCEOFFICER_HPP
#define COMPLIANCEOFFICER_HPP
#pragma once

#include "Assignment.hpp"

namespace SDMS 
{


  class ComplianceOfficer
  {
    public:
      bool verifyTask(const Assignment& assignment) const;
  };
}
#endif
