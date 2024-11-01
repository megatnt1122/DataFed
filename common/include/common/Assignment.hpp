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
  class Assignment
  { 
   

    //Used to send the base stuff
    std::unique_ptr<IMessage> msg;

    //Sched allocates time once it sets its prio
    double alloc_time;
    
    //Maybe a variable called skills
    //Skills skills; or maybe make this str type
    std::vector<Skills> _skills; //SKILLS WOULD BE AN ENUM OF ALL EXECUTE FUNCS 
   
    //This may not be a vecotr but rather just of their respective 

    //Maybe a variable called requiredTools?
    //Tools requiredTools; Maybe make this str type
    std::vector<Tools> _tools;//tools would be an enum of Globus api and Database api 
    //List of what they can be: Exit command, 1 command, 2 command
    //
    Priority _priority;

    int _Id;
   
  public:
    
    Assignment(){};
    // Example of a member function to print the details of the assignment
    Assignment(const std::vector<Skills>& skills,
               const std::vector<Tools>& tools,
               const Priority& priority, const int& Id)
               : _skills(skills), _tools(tools), _priority(priority), _Id(Id) {};
  
    const std::vector<Skills>& getSkills() const;

    const std::vector<Tools>& getTools() const;

    const Priority& getPriority() const;

    const int& getId() const;
  };
}
#endif

//QUESTIONS:
//-Do I make a setX method for the vars
//
//
//I need to setup skills and tools seperatley probabaly and add a setXfunction
