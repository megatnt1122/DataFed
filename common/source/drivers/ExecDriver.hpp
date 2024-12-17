#ifndef EXECDRIVER_HPP
#define EXECDRIVER_HPP
#pragma once


#include "common/Scheduler.hpp"
#include "common/driver.hpp"
#include "common/InventoryManager.hpp"
#include "common/StaffingCoordinator.hpp"
#include <memory>
#include <mutex>
#include <atomic>
#include <thread>

namespace SDMS 
{
  class ExecDriver
  {
    std::thread m_thread;
    mutable std::mutex mySecondFavoriteDriverMutex;

    public:
      ~ExecDriver();
      ExecDriver(std::shared_ptr<Scheduler> external_scheduler, bool runThreadOnCreation);
      //Constructor of some kind?
      const DRIVER_TYPE getType() const;
      void run();
      std::atomic<bool> keep_running;


      StaffingCoordinator sc;
      InventoryManager im;
      std::shared_ptr<Scheduler> internal_scheduler;
      void stop();
      
  };
}

#endif // SCHEDDRIV
