#ifndef WORKER_HPP
#define WORKER_HPP
#pragma once

#include "Assignment.hpp"
#include "Skills.hpp"
#include "Tools.hpp"
#include <vector>
#include <memory>
#include <thread>
#include <mutex>


namespace SDMS 
{

  enum class WorkerState
            {WORKER_CREATED,
             WORKER_INITALIZED,
             WORKER_FINISHED,
             WORKER_IN_PROGRESS,
             WORKER_ERROR};
  class Worker 
  {
    std::mutex toolMutex;
    std::mutex skillMutex;
    std::mutex assignmentMutex;
    std::mutex stateMutex;
    WorkerState workerState;
    std::vector<Skills> _skills;
    std::vector<std::shared_ptr<Tool>> _tools;
    Assignment m_assignment;
    void _execute();

    public:
      ~Worker();
      Worker& operator=(Worker&& sourceWorker) noexcept;
      explicit Worker(const std::vector<Skills>& skills);
      Worker(Worker&& worker);
            //Need an execute function
      std::thread m_thread;
      

      void pushAssignment(Assignment&& assignment);
      void setSkills(const std::vector<Skills> skills);
      void setTools(const std::vector<std::shared_ptr<Tool>>& tools);
      const std::vector<Skills>& getSkills();
      const std::vector<std::shared_ptr<Tool>>& getTools();
      void setState(WorkerState newState);
      WorkerState getState();
      void execute(Assignment&& assignment, std::vector<std::shared_ptr<Tool>> tools);
  };
}
#endif
