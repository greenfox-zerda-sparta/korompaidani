#include "treasure.hpp"

treasure::treasure() {
  this->map_size = 10;
  this->location.resize(map_size);
  for (int i = 0; i < location.size(); i++) {
    this->location[i].resize(map_size, 0);
  }
  this->treasure_pic_path = "pics/treasure.bmp";
  this->coord_x = 0;
  this->coord_y = 0;
  this->actual_pos = 0;
  this->treasure_catch_checker = 0;
  this->catch_counter = 0;
}

treasure::~treasure() {
}

std::string treasure::get_treasure_pic_path() {
  return this->treasure_pic_path;
}

int treasure::get_catch_counter()
{
  return catch_counter;
}

int treasure::get_actual_pos() {
  return actual_pos;
}

void treasure::appear(GameContext &context, level_builder &in_level) {
  if (treasure_catch_checker == 0) {
    coord_y = rand() % map_size;
    coord_x = rand() % map_size;
    if (in_level.get_map(coord_y, coord_x) != 0) {
      location[coord_y][coord_x] = 1;
      treasure_catch_checker = 1;
    }
  }
  actual_pos = (coord_x * map_size) + coord_y;
  context.draw_sprite(get_treasure_pic_path(), 72 * coord_x, 72 * coord_y);
}

void treasure::picked_up(int fight_result, int hero_pos) {
  if (hero_pos == actual_pos && fight_result == 9) {
    treasure_catch_checker = 0;
    catch_counter++;
  }
}

void treasure::set_map_size(int in_map_size) {
  this->map_size = in_map_size;
}