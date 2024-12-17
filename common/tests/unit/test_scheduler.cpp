#define BOOST_TEST_MAIN

#define BOOST_TEST_MODULE scheduler_test 
#include <boost/test/unit_test.hpp>

#include "common/Scheduler.hpp"
#include "common/Assignment.hpp"

using namespace SDMS;

BOOST_AUTO_TEST_SUITE(SchedulerTest)

BOOST_AUTO_TEST_CASE(testing_scheduler) {

  Scheduler scheduler(SchedulerOrder::FIFO);
  
  std::vector<Skills> skills = {Skills::ALLOC_CREATE};
  std::vector<ToolType> tools = {ToolType::GlobusApi};
  Priority priority = Priority::High;
  int id = 1;

  Assignment testAssignment1(skills, tools, priority, id);

  //Add an assignment
  scheduler.addAssignment(std::move(testAssignment1));
  
  //check if true
  BOOST_CHECK(scheduler.popAssignment().getToolTypes().at(0) == ToolType::GlobusApi);
}

BOOST_AUTO_TEST_CASE(testing_schedulerSize) {

 Scheduler scheduler(SchedulerOrder::FIFO);

  std::vector<Skills> skills = {Skills::ALLOC_CREATE};
  std::vector<ToolType> tools = {ToolType::GlobusApi};
  Priority priority = Priority::High;
  int id = 1;

  Assignment testAssignment1(skills, tools, priority, id);


  //Add an assignment
  scheduler.addAssignment(std::move(testAssignment1));
  
  //check if true
  BOOST_CHECK(scheduler.sizeAssignments() == 1);
}



BOOST_AUTO_TEST_SUITE_END()


