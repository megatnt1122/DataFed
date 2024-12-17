#include "common/ComplianceOfficer.hpp"
#include <iostream>
#include <vector>
#include <algorithm> // for std::find
#include "common/Tools.hpp"
#include "common/Skills.hpp"
#include "common/Assignment.hpp"

namespace SDMS 
{  
  bool ComplianceOfficer::verifyTask(const Assignment& assignment) const
  {
    // Assuming Assignment has a method to get the corresponding Skills
    std::vector<Skills> skills = assignment.getSkills(); // This should return a Skills enum

    // Create a vector of available skills
    std::vector<Skills> skillEnum = {Skills::ALLOC_CREATE, Skills::ALLOC_DESTROY, Skills::EXIT};

    for (const Skills& skill : skills)
    {

      // Check if the skill is in the list - WARNING: IF THE VALUE IS NOT FOUND IT RETURNS THE ITERATOR IN THE LAST POSITION THIS IS BAD BECAUSE IF WE ARE LOOKING FOR THE ITEM IN THE LAST POSITION THEN WE WILL RETURN FALSE
      if(std::find(skillEnum.begin(), skillEnum.end(), skill) == skillEnum.end())
      {
        // IF THIS IS AN ERROR AND DOESNT EXIST:
        std::cout << "This assignment's skill doesn't exist!" << std::endl;
        return false;
      }
      else 
      {
        return true;
      }    
    }
  }
}

//Later in development maybe flesh this out to also verify the msg, tools, et0c
//
//We are theorizing to have the comp officer be in between different types of workers... to enforce their specific roles and to check incase some step out of line
