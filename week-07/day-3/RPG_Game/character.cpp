#include "character.hpp"

character::character() {
  this->location.resize(10);  ///ha mukodik akkor a getmapsize kell majd ide
  for (int i = 0; i < location.size(); i++) {
    location[i].resize(10, 0);
  }
  character_pic_down_path = "pics/hero-down.bmp";
  character_pic_up_path = "pics/hero-up.bmp";
  character_pic_left_path = "pics/hero-left.bmp";
  character_pic_right_path = "pics/hero-right.bmp";
  choosen_direction = 'd';
  int coord_x = 0;
  int coord_y = 0;
  location[coord_y][coord_x] = 1;
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

void character::print_map(level_builder &level) {
  for (int i = 0; i < level.get_map_size(); i++) {
    for (int j = 0; j < level.get_map_size(); j++) {
      std::cout << level.get_map(i, j) << ' ';
    }
    std::cout << std::endl;
  }
}

void character::print_loc() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      std::cout << location[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

void character::character_walk(GameContext &context, level_builder &level) {
  std::cout << "coord_x = " << coord_x << std::endl << std::endl;
  if (context.was_key_pressed(ARROW_DOWN) == true && coord_y < 9) {
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
  else if (context.was_key_pressed(ARROW_RIGHT) == true && coord_x < 9) { ///instead of 9 u have to use variable
    if ((level.get_map(coord_y, coord_x + 1)) != 0) {
      coord_x++;
      location[coord_y][coord_x] = 1;
      choosen_direction = 'r';
    }
  }
  context.draw_sprite(get_character_pic_path(choosen_direction), 72 * coord_x, 72 * coord_y);
}

