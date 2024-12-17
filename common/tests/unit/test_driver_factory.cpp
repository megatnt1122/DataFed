#define BOOST_TEST_MAIN

#define BOOST_TEST_MODULE driver_factory
#include <boost/test/unit_test.hpp>

#include "common/driver_factory.hpp"
#include "common/driver.hpp"
#include "drivers/SchedDriver.hpp"
#include "drivers/ExecDriver.hpp"
#include "common/ComplianceOfficer.hpp"
#include "common/Manager.hpp"
#include "common/Scheduler.hpp"
#include "common/Assignment.hpp"
#include <boost/circular_buffer.hpp>
#include <chrono>

using namespace SDMS;

BOOST_AUTO_TEST_SUITE(DriverFactoryTest)

BOOST_AUTO_TEST_CASE(testing_sched_driver) {
//
    //Initalize the managexr
    auto scheduler = std::make_shared<Scheduler>();

    //Creating  the assignments
    std::vector<Skills> skills1 = {Skills::ALLOC_CREATE};
    std::vector<ToolType> tools1 = {ToolType::GlobusApi};
    Priority priority1 = Priority::High;
    int id1 = 1;

    std::vector<Skills> skills2 = {Skills::ERROR_TEST};
    std::vector<ToolType> tools2 = {ToolType::GlobusApi};
    Priority priority2 = Priority::High;
    int id2 = 2;

    std::vector<Skills> skills3 = {Skills::EXIT};
    std::vector<ToolType> tools3 = {ToolType::GlobusApi};
    Priority priority3 = Priority::High;
    int id3 = 3;



  //NOTE: Need to rewrite Driver Factory to be able to take in a manager, sched, Co, and error buffer
  SchedDriver driver(scheduler, true);

  std::cout << "Starting Tests" << std::endl;
  //Start of our testing
  Assignment testAssignment1(skills1, tools1, priority1, id1);
 driver.addManagerAssignment(std::move(testAssignment1));

  Assignment testAssignment2(skills2, tools2, priority2, id2);
  driver.addManagerAssignment(std::move(testAssignment2));

  sleep(5);
  Assignment testAssignment3(skills3, tools3, priority3, id3);
  driver.addManagerAssignment(std::move(testAssignment3));

  std::cout << "End of Test" << std::endl;

  BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(testing_exec_driver)
{
    //Initalize the managexr
    auto scheduler = std::make_shared<Scheduler>();

    //Creating  the assignments
    std::vector<Skills> skills1 = {Skills::ALLOC_CREATE};
    std::vector<ToolType> tools1 = {ToolType::GlobusApi};
    Priority priority1 = Priority::High;
    int id1 = 1;

    std::vector<Skills> skills2 = {Skills::ERROR_TEST};
    std::vector<ToolType> tools2 = {ToolType::GlobusApi};
    Priority priority2 = Priority::High;
    int id2 = 2;

    //Initalize driver
    ExecDriver driver(scheduler, true);

    std::cout << "Starting Tests" << std::endl;

    Assignment testAssignment1(skills1, tools1, priority1, id1);
    scheduler->addAssignment(std::move(testAssignment1));

    Assignment testAssignment2(skills2, tools2, priority2, id2);
    scheduler->addAssignment(std::move(testAssignment2));
    sleep(5);

  
  BOOST_CHECK(true);
}


BOOST_AUTO_TEST_SUITE_END()


