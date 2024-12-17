#ifndef STAFFING_COORDINATOR_HPP
#define STAFFING_COORDINATOR_HPP
#pragma once

#include <vector>
#include "Assignment.hpp"
#include "Worker.hpp"
#include <mutex>
#include <boost/circular_buffer.hpp>

namespace SDMS 
{
  class StaffingCoordinator
  {
    public:
      mutable std::mutex myFavoriteSCMutex;
      Worker& hireWorker(Assignment& assignment);
      void removeWorker();
      Assignment grabNextAssignment(std::vector<Assignment> internalList) const;

      std::vector<Worker> m_workers;
      bool reachedMaxWorkers();
      int numOfWorkers = 0;
     // boost::circular_buffer<Worker::WorkerState> state_buffer(5);


  };
}
#endif
