#include "character.hpp"

character::character() {
  this->map_size = 10;
  this->location.resize(map_size);
  for (int i = 0; i < location.size(); i++) {
    this->location[i].resize(map_size, 0);
  }
  this->character_pic_down_path = "pics/hero-down.bmp";
  this->character_pic_up_path = "pics/hero-up.bmp";
  this->character_pic_left_path = "pics/hero-left.bmp";
  this->character_pic_right_path = "pics/hero-right.bmp";
  this->choosen_direction = 'd';
  this->coord_x = 0;
  this->coord_y = 0;
  this->actual_pos = 0;
  this->location[this->coord_y][this->coord_x] = 1;
}

character::~character() {
}

std::string character::get_character_pic_path(char direction) {
  if (direction == 'd') {
    return character_pic_down_path;
  }
  else if (direction == 'u') {
    return character_pic_up_path;
  }
  else if (direction == 'l') {
    return character_pic_left_path;
  }
  else if (direction == 'r') {
    return character_pic_right_path;
  }
}

int character::get_actual_pos() {
  return actual_pos;
}

void character::character_walk(GameContext &context, level_builder &level) {
  if (context.was_key_pressed(ARROW_DOWN) == true && coord_y < map_size -  1) {
    if ((level.get_map(coord_y + 1, coord_x)) != 0) {
      coord_y++;
      location[coord_y][coord_x] = 1;
      choosen_direction = 'd';
    }
  }
  else if (context.was_key_pressed(ARROW_UP) == true && coord_y > 0) {
    if ((level.get_map(coord_y - 1, coord_x)) != 0) {
      coord_y--;
      location[coord_y][coord_x] = 1;
      choosen_direction = 'u';
    }
  }
  else if (context.was_key_pressed(ARROW_LEFT) == true && coord_x > 0) {
    if ((level.get_map(coord_y, coord_x - 1)) != 0) {
      coord_x--;
      location[coord_y][coord_x] = 1;
      choosen_direction = 'l';
    }
  }
  else if (context.was_key_pressed(ARROW_RIGHT) == true && coord_x < map_size - 1) {
    if ((level.get_map(coord_y, coord_x + 1)) != 0) {
      coord_x++;
      location[coord_y][coord_x] = 1;
      choosen_direction = 'r';
    }
  }
  actual_pos = (coord_x * 10) + coord_y;
  context.draw_sprite(get_character_pic_path(choosen_direction), 72 * coord_x, 72 * coord_y);
}

int character::character_fight(GameContext &context) {
  if (context.was_key_pressed(SPACE) == true) {
    return 9;
  }
  else {
    return 1;
  }
}

void character::set_map_size(int in_map_size) {
  this->map_size = in_map_size;
}