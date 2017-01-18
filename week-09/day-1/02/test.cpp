#ifdef _TEST
#include "stdafx.h"
#define CATCH_CONFIG_MAIN
#include "C:\Users\korom\OneDrive\Programming\TEST\catch.hpp"
#include "Container.hpp"

TEST_CASE("Sum of my test vector") {
  std::vector<int> vec;
  vec.push_back(5);
  vec.push_back(6);
  Container c;
  REQUIRE(c.get_sum_of_your_vector(vec) == 11);
}
#endif