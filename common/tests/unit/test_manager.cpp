#define BOOST_TEST_MAIN

#define BOOST_TEST_MODULE Manager 
#include <boost/test/unit_test.hpp>
#include "common/Manager.hpp"
#include "common/Assignment.hpp"

using namespace SDMS;

BOOST_AUTO_TEST_SUITE(test_manager)

BOOST_AUTO_TEST_CASE(testing_manager)
{
  Manager manager = Manager();
  //Setup assignment with //Assignment(skills, tools, priority, Id)
  Assignment testAssignment1 = Assignment(ALLOC_CREATE, GlobusApi, High, 1); 
 
  //Add an assignment
  manager.addAssignment(testAssignment1)
  
  
  //check if true
  BOOST_CHECK(testAssignment1.getTools().at(0) == Tools::GlobusApi);
  //BOOST_CHECK(testAssignment1.getTools().at(0) == Tools::GlobusApi);
}


BOOST_AUTO_TEST_SUITE_END()


