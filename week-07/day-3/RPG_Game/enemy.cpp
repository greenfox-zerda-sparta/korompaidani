#include "enemy.hpp"

enemy::enemy(level_builder &in_level) {
  this->level = &in_level;
}

enemy::enemy() {
  this->location.resize(10);  ///ha mukodik akkor a getmapsize kell majd ide
  for (int i = 0; i < location.size(); i++) {
    this->location[i].resize(10, 0);
  }
  this->enemy_pic_path = "pics/skeleton.bmp";
  this->coord_x = 0;
  this->coord_y = 0;
  this->actual_pos = 0;
  this->enemy_hp_counter = 0;
}

enemy::~enemy() {
}


std::string enemy::get_enemy_pic_path() {
  return this->enemy_pic_path;
}

int enemy::get_actual_pos() {
  return actual_pos;
}

void enemy::enemy_appear(GameContext &context, level_builder &in_level) {
  if (enemy_hp_counter == 0) {
    coord_y = rand() % 10;
    coord_x = rand() % 10;
    if (in_level.get_map(coord_y, coord_x) != 0) {
      location[coord_y][coord_x] = 1;
      enemy_hp_counter = 1;
    }
  }
  actual_pos = (coord_x * 10) + coord_y;
  context.draw_sprite(get_enemy_pic_path(), 72 * coord_x, 72 * coord_y);
}

void enemy::enemy_death(int fight_result, int hero_pos) {
  if (hero_pos == actual_pos && fight_result == 9) {
    enemy_hp_counter = 0;
  }
}

void enemy::print_level_map(level_builder &level) {
  for (int i = 0; i < level.get_map_size(); i++) {
    for (int j = 0; j < level.get_map_size(); j++) {
      std::cout << level.get_map(i, j) << ' ';
    }
    std::cout << std::endl;
  }
}
