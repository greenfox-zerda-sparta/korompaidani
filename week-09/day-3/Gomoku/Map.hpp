#pragma once
#include "ERROR_CODES.hpp"
#include <vector>

class Map {
private:
  const unsigned short int MAP_SIZE;
  std::vector<std::vector <unsigned short int> > map;
public:
  Map(unsigned short int);
  unsigned short int get_map_size();
  unsigned short int get_map_value_by_coordinates(unsigned short int, unsigned short int);
  unsigned short int set_map_value_by_coordinates(unsigned short int, unsigned short int, unsigned short int);
  std::vector<std::vector <unsigned short int> > get_map();
};