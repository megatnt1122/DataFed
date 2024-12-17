#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP
#pragma once

#include "Skills.hpp"
#include "Tools.hpp"
#include "Priority.hpp"
#include "IMessage.hpp"
#include <memory>
#include <vector>

namespace SDMS 
{
  enum AssignmentState
            {ASSIGNMENT_CREATED,
             ASSIGNMENT_INITALIZED,
             ASSIGNMENT_FINISHED,
             ASSIGNMENT_IN_PROGRESS,
             ASSIGNMENT_ERROR};
  class Assignment
  { 
   
    //Used to send the base stuff
    std::unique_ptr<IMessage> msg;

    //Sched allocates time once it sets its prio
    double alloc_time;
    
    //Maybe a variable called skills
    //Skills skills; or maybe make this str type
    std::vector<Skills> _skills; //SKILLS WOULD BE AN ENUM OF ALL EXECUTE FUNCS 
  
    AssignmentState assignmentState;
    //This may not be a vecotr but rather just of their respective 

    //Maybe a variable called requiredTools?
    //Tools requiredTools; Maybe make this str type
    std::vector<ToolType> _toolTypes;//tools would be an enum of Globus api and Database api 
    //List of what they can be: Exit command, 1 command, 2 command
    //
    Priority _priority;

    int _Id;
   
  public:
    
    Assignment(){};
    // Example of a member function to print the details of the assignment
    Assignment(const std::vector<Skills>& skills,
               const std::vector<ToolType>& toolTypes,
               const Priority& priority, const int& Id)
               : _skills(skills), _toolTypes(toolTypes), _priority(priority), _Id(Id) {};
  
    const std::vector<Skills>& getSkills() const;
    std::vector<Skills> getSkills();

    const std::vector<ToolType>& getToolTypes() const;

    const Priority& getPriority() const;

    const int& getId() const;

    AssignmentState getState() const;

    void setState(AssignmentState newState);
  };
}
#endif

//QUESTIONS:
//-Do I make a setX method for the vars
//
//
//I need to setup skills and tools seperatley probabaly and add a setXfunction
