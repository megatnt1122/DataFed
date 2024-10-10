#define BOOST_TEST_MAIN

#define BOOST_TEST_MODULE Manager 
#include <boost/test/unit_test.hpp>
#include "common/Manager.hpp"

using namespace SDMS;

BOOST_AUTO_TEST_SUITE(test_manager)

BOOST_AUTO_TEST_CASE(testing_manager)
{
  Manager manager = Manager();
  
  //check if true
  BOOST_CHECK(manager.getAssignments());
}


BOOST_AUTO_TEST_SUITE_END()


