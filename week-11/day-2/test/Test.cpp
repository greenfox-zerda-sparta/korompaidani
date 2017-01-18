#include "Test.hpp"
#include <iostream>

Test::Test(int x) throw(int) {
  if (x == 0) {
    throw 1;
  }
  number = 10 / x;
  std::cout << number << std::endl;
}

Test::~Test() {
}
