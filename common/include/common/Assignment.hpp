#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP
#pragma once

namespace SDMS 
{

  class Assignment
  {
    //Used to send the base stuff
    std::unique_ptr<IMessage> msg;

    //Sched allocates time once it sets its prio
    double alloc_time;
    
    //Maybe a variable called skills
    //Skills skills; or maybe make this str type
    std::vector<Skills> skills; //SKILLS WOULD BE AN ENUM OF ALL EXECUTE FUNCS 
    
    //Maybe a variable called requiredTools?
    //Tools requiredTools; Maybe make this str type
    std::vector<Tools> tools;//tools would be an enum of Globus api and Database api
    //Needs seperate types maybe??? 
    //List of what they can be: Exit command, 1 command, 2 command
    //str command;
    
  };
}
#endif
