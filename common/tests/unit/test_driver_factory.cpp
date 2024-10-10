#define BOOST_TEST_MAIN

#define BOOST_TEST_MODULE driver_factory
#include <boost/test/unit_test.hpp>

#include "common/driver_factory.hpp"
#include "common/driver.hpp"

using namespace SDMS;

BOOST_AUTO_TEST_SUITE(DriverFactoryTest)

BOOST_AUTO_TEST_CASE(testing_factory_creation) {

  DriverFactory driver_factory;

  std::unique_ptr<Driver> driver = driver_factory.create(DRIVER_TYPE::SCHED_DRIVER);

  BOOST_CHECK(driver->run());
}


BOOST_AUTO_TEST_SUITE_END()


