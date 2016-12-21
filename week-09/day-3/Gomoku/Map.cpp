#include "Map.hpp"

Map::Map() : MAP_SIZE(19) {
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

unsigned short int Map::set_map_value_by_coordinates(unsigned short int x, unsigned short int y, int value) {
  if (this->get_map_value_by_coordinates(x, y) != ERR_CODE_9) {
    map[y][x] = value;
    return value;
  }
  return ERR_CODE_9;
}
