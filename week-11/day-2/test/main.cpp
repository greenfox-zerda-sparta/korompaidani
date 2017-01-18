#include "waste\stdafx.h"
#define CATCH_CONFIG_MAIN
#include <iostream>

#ifdef CATCH_CONFIG_MAIN
#include "Test.hpp"
using std::cin;
using std::cout;
using std::string;
using std::endl;

int main(int argc, char* argv[]) {
  /*Test* test;
  try {
    test = new Test(0);
  }
  catch (int) {
    std::cout << "Object not created." << std::endl;
    return 0;
  }
  delete test;
  return 0;*/
  try {
    try {
      // code here
    }
    catch (int n) {
      throw;
    }
  }
  catch (...) {
    cout << "Exception occurred";
  }
  return 0;
}

#endif

#ifndef CATCH_CONFIG_MAIN
#include "C:\Users\korom\OneDrive\Programming\TEST\catch.hpp"

TEST_CASE("test 1") {
  CHECK(0);
}

#endif