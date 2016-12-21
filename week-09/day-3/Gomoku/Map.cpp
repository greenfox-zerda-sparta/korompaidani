#include "Map.hpp"

Map::Map(unsigned short int size) : MAP_SIZE(size) {
  map.resize(MAP_SIZE);
  for (int i = 0; i < map.size(); i++) {
    map[i].resize(MAP_SIZE, 0);
  }
}

unsigned short int Map::get_map_value_by_coordinates(unsigned short int x, unsigned short int y) {
  if (x < MAP_SIZE && y < MAP_SIZE && x >= 0 && y >= 0) {
    return map[y][x];
  }
  return ERR_CODE_9;
}

unsigned short int Map::set_map_value_by_coordinates(unsigned short int x, unsigned short int y, unsigned short int value) {
  if (this->get_map_value_by_coordinates(x, y) != ERR_CODE_9 && this->get_map_value_by_coordinates(x, y) == 0) {
    map[y][x] = value;
    return value;
  }
  return ERR_CODE_8;
}

std::vector<std::vector <unsigned short int> > Map::get_map() {
  return map;
}
