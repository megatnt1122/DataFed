#define BOOST_TEST_MAIN

#define BOOST_TEST_MODULE ComplianceOfficer
#include <boost/test/unit_test.hpp>
#include "common/ComplianceOfficer.hpp"

using namespace SDMS;

BOOST_AUTO_TEST_SUITE(test_compliance_officer)

BOOST_AUTO_TEST_CASE(testing_compliance_officer)
{
  ComplianceOfficer co = ComplianceOfficer();
  
  //Set assignment
  bool assignment = true;
  
  //check if true
  BOOST_CHECK(co.verifyTask(assignment));
}


BOOST_AUTO_TEST_SUITE_END()
