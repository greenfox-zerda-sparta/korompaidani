#include "enemy.hpp"

char dir[4] = { 'd', 'u', 'l', 'r' };
int dir_index = rand() % 4;

enemy::enemy() : MOVING_SPEED(40) {
  this->map_size = 10;
  this->location.resize(map_size);
  for (int i = 0; i < location.size(); i++) {
    this->location[i].resize(map_size, 0);
  }
  this->enemy_pic_path = "pics/skeleton.bmp";
  this->enemy_pic_down_path = "pics/molaram-down.bmp";
  this->enemy_pic_up_path = "pics/molaram-up.bmp";
  this->enemy_pic_left_path = "pics/molaram-left.bmp";
  this->enemy_pic_right_path = "pics/molaram-right.bmp";
  this->coord_x = 0;
  this->coord_y = 0;
  this->actual_pos = 0;
  this->enemy_hp_counter = 0;
  this->death_counter = 0;
  this->pulse = 0;
  this->choosen_direction = 'd';
}

enemy::~enemy() {
}


std::string enemy::get_enemy_pic_path(char direction) {
  if (direction == 'd') {
    return enemy_pic_down_path;
  }
  else if (direction == 'u') {
    return enemy_pic_up_path;
  }
  else if (direction == 'l') {
    return enemy_pic_left_path;
  }
  else if (direction == 'r') {
    return enemy_pic_right_path;
  }
}

int enemy::get_actual_pos() {
  return actual_pos;
}

int enemy::get_death_counter() {
  return death_counter;
}

void enemy::enemy_appear(GameContext &context, level_builder &in_level) {
  if (enemy_hp_counter == 0) {
    coord_y = rand() % map_size;
    coord_x = rand() % map_size;
    if (in_level.get_map(coord_y, coord_x) != 0) {
      location[coord_y][coord_x] = 1;
      enemy_hp_counter = 1;
    }
  }
  enemy_walk(context, in_level);
  actual_pos = (coord_x * map_size) + coord_y;
  context.draw_sprite(get_enemy_pic_path(choosen_direction), 72 * coord_x, 72 * coord_y);
}

void enemy::enemy_walk(GameContext &context, level_builder &in_level) {
  if (increase_pulse() == MOVING_SPEED) {
    switch (dir[dir_index]) {
    case 'd':
      if (coord_y < map_size - 1) {
        if (in_level.get_map(coord_y + 1, coord_x) != 0) {
          choosen_direction = 'd';
          coord_y++;
          location[coord_y][coord_x] = 1;
        }
        else {
          dir_index = rand() % 4;
        }
      }
      else {
        dir_index = rand() % 4;
      }
      break;
    case 'u':
      if (coord_y > 0) {
        if (in_level.get_map(coord_y - 1, coord_x) != 0) {
          choosen_direction = 'u';
          coord_y--;
          location[coord_y][coord_x] = 1;
        }
        else {
          dir_index = rand() % 4;
        }
      }
      else {
        dir_index = rand() % 4;
      }
      break;
    case 'l':
      if (coord_x > 0) {
        if (in_level.get_map(coord_y, coord_x - 1) != 0) {
          choosen_direction = 'l';
          coord_x--;
          location[coord_y][coord_x] = 1;
        }
        else {
          dir_index = rand() % 4;
        }
      }
      else {
        dir_index = rand() % 4;
      }
      break;
    case 'r':
      if (coord_x < map_size - 1) {
        if (in_level.get_map(coord_y, coord_x + 1) != 0) {
          choosen_direction = 'r';
          coord_x++;
          location[coord_y][coord_x] = 1;
        }
        else {
          dir_index = rand() % 4;
        }
      }
      else {
        dir_index = rand() % 4;
      }
      break;
    default:
      dir_index = rand() % 4;
    }
  }
}

void enemy::enemy_death(int fight_result, int hero_pos) {
  if (hero_pos == actual_pos && fight_result == map_size - 1) {
    enemy_hp_counter = 0;
    death_counter++;
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

int enemy::increase_pulse() {
  unsigned short int temp_pulse = 0;
  pulse++;
  if (pulse == MOVING_SPEED) {
    temp_pulse = pulse;
    pulse = 0;
    return temp_pulse;
  }
  return temp_pulse;
}

void enemy::set_enemy_picture(char enemy_type) {
  if (enemy_type == 's') {
    this->enemy_pic_down_path = "pics/snake-down.bmp";
    this->enemy_pic_up_path = "pics/snake-up.bmp";
    this->enemy_pic_left_path = "pics/snake-left.bmp";
    this->enemy_pic_right_path = "pics/snake-right.bmp";
  }
  else if (enemy_type == 'm') {
    this->enemy_pic_down_path = "pics/molaram-down.bmp";
    this->enemy_pic_up_path = "pics/molaram-up.bmp";
    this->enemy_pic_left_path = "pics/molaram-left.bmp";
    this->enemy_pic_right_path = "pics/molaram-right.bmp";
  }
  else if (enemy_type == 's') {
    this->enemy_pic_down_path = "pics/soldier-down.bmp";
    this->enemy_pic_up_path = "pics/soldier-up.bmp";
    this->enemy_pic_left_path = "pics/soldier-left.bmp";
    this->enemy_pic_right_path = "pics/soldier-right.bmp";
  }
}

void enemy::set_map_size(int in_map_size) {
  this->map_size = in_map_size;
}