#define BOOST_TEST_MAIN

#define BOOST_TEST_MODULE ComplianceOfficer
#include <boost/test/unit_test.hpp>
#include "common/ComplianceOfficer.hpp"
#include "common/Assignment.hpp"

using namespace SDMS;

BOOST_AUTO_TEST_SUITE(test_compliance_officer)

BOOST_AUTO_TEST_CASE(testing_compliance_officer)
{
  ComplianceOfficer co = ComplianceOfficer();

//Set assignment
std::vector<Skills> skills = {Skills::ALLOC_CREATE};
std::vector<ToolType> tools = {ToolType::GlobusApi};
Priority priority = Priority::High;
int id = 1;

Assignment testAssignment1(skills, tools, priority, id);
  
  //check if true
  BOOST_CHECK(co.verifyTask(testAssignment1));
}


BOOST_AUTO_TEST_SUITE_END()
