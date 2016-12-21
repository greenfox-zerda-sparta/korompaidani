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

void print_map_vector(Map&);

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

TEST_CASE("set map value by coordinates edge cases") {
  Map map;
  int my_num = 2;
  REQUIRE(map.set_map_value_by_coordinates(4, 19, my_num) == ERR_CODE_9);
}

TEST_CASE("get map visibility test") {
  Map map;  
  REQUIRE(map.get_map().size() == 19);
  REQUIRE(map.get_map()[1].size() == 19);
  REQUIRE(map.get_map()[18].size() == 19);
}

TEST_CASE("set values and use get map to print map") {
  Map map;
  unsigned int my_num = 5;
  map.set_map_value_by_coordinates(-1, -1, my_num);
  map.set_map_value_by_coordinates(0, 0, my_num);
  map.set_map_value_by_coordinates(19, 19, my_num);
  map.set_map_value_by_coordinates(18, 18, my_num);
  map.set_map_value_by_coordinates(4, 11, my_num);
  
  print_map_vector(map);
}
#endif

void print_map_vector(Map& m_map) {
  for (int i = 0; i < m_map.get_map().size(); i++) {
    for (int j = 0; j < m_map.get_map()[i].size(); j++) {
      std::cout << m_map.get_map()[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}