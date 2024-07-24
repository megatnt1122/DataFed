#define BOOST_TEST_MAIN

#define BOOST_TEST_MODULE socket_options
#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>

// Local private includes
#include "common/SocketOptions.hpp"
#include "common/TraceException.hpp"

// Standard includes
#include <iostream>

using namespace SDMS;

BOOST_AUTO_TEST_SUITE(SocketOptionsTest)

BOOST_AUTO_TEST_CASE(testing_AddressSplitterTCP) {

  AddressSplitter splitter("tcp://www.datafed.com:54234");

  BOOST_CHECK(splitter.host().compare("www.datafed.com") == 0);
  BOOST_CHECK(splitter.port() == 54234);
  BOOST_CHECK(splitter.scheme() == URIScheme::TCP);
}

BOOST_AUTO_TEST_CASE(testing_AddressSplitterINPROC) {

  AddressSplitter splitter("inproc://www.datafed.com:54234");

  BOOST_CHECK(splitter.host().compare("www.datafed.com") == 0);
  BOOST_CHECK(splitter.port() == 54234);
  BOOST_CHECK(splitter.scheme() == URIScheme::INPROC);
}

BOOST_AUTO_TEST_CASE(testing_AddressSplitterNoPort) {

  // Still contains ':'
  BOOST_CHECK_THROW(AddressSplitter splitter("inproc://www.datafed.com:"),
                    TraceException);
}

BOOST_AUTO_TEST_CASE(testing_AddressSplitterNoPort2) {

  // Does not contain ':'
  AddressSplitter splitter("inproc://www.datafed.com");

  BOOST_CHECK(splitter.host().compare("www.datafed.com") == 0);
  BOOST_CHECK(splitter.scheme() == URIScheme::INPROC);

  if (auto port = splitter.port(); port) {
    // Should not execute because port should not be defined
    BOOST_CHECK(false);
  }
}
////////////////////////////////////////
///       START OF HTTP TESTING     ///
//////////////////////////////////////
BOOST_AUTO_TEST_CASE(testing_AddressSplitterHTTP) {

  AddressSplitter splitter("http://localhost:8080");

  BOOST_CHECK(splitter.host().compare("localhost") == 0);
  BOOST_CHECK(splitter.port() == 8080);
  BOOST_CHECK(splitter.scheme() == URIScheme::HTTP);
}


BOOST_AUTO_TEST_SUITE_END()
