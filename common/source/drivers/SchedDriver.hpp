#ifndef SCHEDDRIVER_HPP
#define SCHEDDRIVER_HPP
#pragma once

#include "common/driver.hpp"
#include "common/Assignment.hpp"
#include "common/ComplianceOfficer.hpp"
#include "common/Manager.hpp"
#include "common/Scheduler.hpp"
#include <memory>
#include <mutex>
#include <atomic>
#include <thread>

namespace SDMS 
{
  class SchedDriver
  {
    std::thread m_thread;
    mutable std::mutex myFavoriteDriverMutex;

    public:
      ~SchedDriver();
      SchedDriver(std::shared_ptr<Scheduler> external_scheduler, bool runThreadOnCreation);
      const DRIVER_TYPE getType() const;
      void run();
      std::atomic<bool> keep_running;

      Manager manager;
      std::shared_ptr<Scheduler> internal_scheduler;
      ComplianceOfficer complianceOfficer;
      void addManagerAssignment(Assignment&& assignment);
      void setManager(Manager outerManager);
      void setComplianceOfficer(ComplianceOfficer outerComplianceOfficer);
      void stop();
  };
}

#endif // SCHEDDRIVER_HPP
       //
       //Note SchedDriver(Manager, SchedDriver, CO)
       ////Main
       ///
       ///Make sure to set for the complianceOfficer,schedulerand manager,
       ///
       ///Make sure to send manager syncronously to each driver taht is in need of it, for testing we are moving the manager to the specific driver THIS ISNT WHAT WE WANT! 
