#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
#pragma once

#include "Assignment.hpp"
#include "Priority.hpp"
#include "SchedulerOrder.hpp"
#include <vector>
#include <mutex>

namespace SDMS 
{

  class Scheduler
  {
     
    std::vector<std::pair<int,Priority>> _internalList;
    std::vector<Assignment> _internalAssignmentList;
    SchedulerOrder m_sort_order = SchedulerOrder::FIFO;
    mutable std::mutex myFavoriteMutex;

  public:
    Scheduler(){};
    Scheduler(const SchedulerOrder sort_order) : m_sort_order(sort_order) {};
    void addAssignment(Assignment&& assignment);
    Assignment popAssignment();
    int sizeAssignments() const;
  };
}
#endif

//Notes:
//  Do I situate this so that it i
