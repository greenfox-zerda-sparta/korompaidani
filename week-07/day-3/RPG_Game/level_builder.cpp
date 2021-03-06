#include "level_builder.hpp"

const int STEPS[15] = { 3,3,4,5,4,4,4,5,5,5,5,5,6,6,6 };
const int COVERABLE = 54;

level_builder::level_builder() {
  this->map_size = 10;
  this->map.resize(map_size);
  for (int i = 0; i < map.size(); i++) {
    map[i].resize(map_size, 0);
  }
  wall_pic_path = "pics/wall.bmp";
  floor_pic_path = "pics/floor.bmp";
}


level_builder::~level_builder() {
}

void level_builder::drawer(int x, int y, int covered) {
}

std::string level_builder::get_wall_pic_path() {
  return this->wall_pic_path;
}

std::string level_builder::get_floor_pic_path() {
  return  this->floor_pic_path;
}

int level_builder::get_map_size() {
  return map_size;
}

int level_builder::get_map(int x, int y) {
  return map[y][x];
}

void level_builder::level_creator(GameContext &context) {
  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map[i].size(); j++) {
      if (map[i][j] == 1) {
        context.draw_sprite(floor_pic_path, i * 72, j * 72);
      }
      else {
        context.draw_sprite(wall_pic_path, i * 72, j * 72);
      }
    }
  }
}