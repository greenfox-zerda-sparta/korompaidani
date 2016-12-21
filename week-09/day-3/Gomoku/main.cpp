#include "waste\stdafx.h"
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "Map.hpp"

#ifndef CATCH_CONFIG_MAIN

int main(int argc, char* argv[]) {
  
  return 0;
}
#endif

#ifdef CATCH_CONFIG_MAIN
#include "C:\Users\korom\OneDrive\Programming\TEST\catch.hpp"
TEST_CASE("get map value by coordinates") {
  Map map;
  REQUIRE(map.get_map_value_by_coordinates(4, 4) == 0);
}

TEST_CASE("get map value by coordinates if coords are more than 19") {
  Map map;
  REQUIRE(map.get_map_value_by_coordinates(4, 19) == ERR_CODE_9);
}

TEST_CASE("get map value by coordinates if coords are less than 0") {
  Map map;
  REQUIRE(map.get_map_value_by_coordinates(-1, -1) == ERR_CODE_9);
}

TEST_CASE("set map value by coordinates") {
  Map map;
  int my_num = 2;
  map.set_map_value_by_coordinates(4, 5, my_num);
  REQUIRE(map.get_map_value_by_coordinates(4, 5) == my_num);
}

#endif
