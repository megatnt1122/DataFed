#include "common/Worker.hpp"
#include <vector>
#include <iostream>
#include <thread>

namespace SDMS
{ 

  Worker::Worker(Worker&& sourceWorker)
  {
    const std::lock_guard<std::mutex> lockTools(sourceWorker.toolMutex);
    const std::lock_guard<std::mutex> lockSkills(sourceWorker.skillMutex); 
    const std::lock_guard<std::mutex> lockAssignment(sourceWorker.assignmentMutex);
    const std::lock_guard<std::mutex> lockState(sourceWorker.stateMutex);

    _tools = std::move(sourceWorker._tools);
    _skills = std::move(sourceWorker._skills);
    m_assignment = std::move(sourceWorker.m_assignment);
    workerState = std::move(sourceWorker.workerState);
  }

  //Move Assignment Operator
  Worker& Worker::operator=(Worker&& sourceWorker) noexcept
  {
    if (this != &sourceWorker)
    {
      const std::lock_guard<std::mutex> lockTools(toolMutex);
      const std::lock_guard<std::mutex> lockSkills(skillMutex); 
      const std::lock_guard<std::mutex> lockAssignment(assignmentMutex);
      const std::lock_guard<std::mutex> lockState(stateMutex);

      const std::lock_guard<std::mutex> lockSourceTools(sourceWorker.toolMutex);
      const std::lock_guard<std::mutex> lockSourceSkills(sourceWorker.skillMutex); 
      const std::lock_guard<std::mutex> lockSourceAssignment(sourceWorker.assignmentMutex);
      const std::lock_guard<std::mutex> lockSourceState(sourceWorker.stateMutex);
    }
    return *this;
  }

  Worker::~Worker()
  {
    if(m_thread.joinable())
    {
      m_thread.join();
    }
  }
  Worker::Worker(const std::vector<Skills>& skills)
  {
    setSkills(skills);
    setState(WorkerState::WORKER_INITALIZED); 
  }
  
  void Worker::setSkills(const std::vector<Skills> skills)
  {
    std::lock_guard<std::mutex> lock(skillMutex);
    _skills = skills; 
  }

  const std::vector<Skills>& Worker::getSkills()
  {
    std::lock_guard<std::mutex> lock(skillMutex);
    return _skills; 
  }
  
  void Worker::setTools(const std::vector<std::shared_ptr<Tool>>& tools)
  {
    std::lock_guard<std::mutex> lock(toolMutex);
    _tools = tools; 
  }

  const std::vector<std::shared_ptr<Tool>>& Worker::getTools()
  {
    std::lock_guard<std::mutex> lock(toolMutex);
    return _tools; 
  }

  void Worker::setState(WorkerState newState)
  {
    std::lock_guard<std::mutex> lock(stateMutex);
    workerState = newState;
  }

  WorkerState Worker::getState()
  {
    std::lock_guard<std::mutex> lock(stateMutex);
    return workerState;
  }

  void Worker::execute(Assignment&& assignment, std::vector<std::shared_ptr<Tool>> tools)
  {
    setTools(std::move(tools));
    pushAssignment(std::move(assignment));
    std::cout << "Executing work" << std::endl;
    m_thread = std::thread(&Worker::_execute, this);
  }

  void Worker::_execute()
  {
    std::cout << "Executing work within Thread" << std::endl; 
  }
  
  void Worker::pushAssignment(Assignment&& assignment)
  {
    std::lock_guard<std::mutex> lock(assignmentMutex);
    m_assignment = std::move(assignment);
  }
}
