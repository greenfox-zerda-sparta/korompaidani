#include "enemy.hpp"

char dir[4] = { 'd', 'u', 'l', 'r' };
int dir_index = rand() % 4;

enemy::enemy(level_builder &in_level) : MOVING_SPEED(50) {
  this->level = &in_level;
}

enemy::enemy() : MOVING_SPEED(100) {
  this->location.resize(10);  ///ha mukodik akkor a getmapsize kell majd ide
  for (int i = 0; i < location.size(); i++) {
    this->location[i].resize(10, 0);
  }
  this->enemy_pic_path = "pics/skeleton.bmp";
  this->coord_x = 0;
  this->coord_y = 0;
  this->actual_pos = 0;
  this->enemy_hp_counter = 0;
  this->death_counter = 0;
  this->pulse = 0;
}

enemy::~enemy() {
}


std::string enemy::get_enemy_pic_path() {
  return this->enemy_pic_path;
}

int enemy::get_actual_pos() {
  return actual_pos;
}

int enemy::get_death_counter() {
  return death_counter;
}

void enemy::enemy_appear_and_walk(GameContext &context, level_builder &in_level) {
  if (enemy_hp_counter == 0) {
    coord_y = rand() % 10;
    coord_x = rand() % 10;
    if (in_level.get_map(coord_y, coord_x) != 0) {
      location[coord_y][coord_x] = 1;
      enemy_hp_counter = 1;
    }
  }
  if (increase_pulse() == MOVING_SPEED) {
    switch (dir[dir_index]) {
    case 'd':
      if (coord_y < 9) {
        if (in_level.get_map(coord_y + 1, coord_x) != 0) {
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
      if (coord_x < 9) {
        if (in_level.get_map(coord_y, coord_x + 1) != 0) {
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

  actual_pos = (coord_x * 10) + coord_y;
  context.draw_sprite(get_enemy_pic_path(), 72 * coord_x, 72 * coord_y);
}

void enemy::enemy_death(int fight_result, int hero_pos) {
  if (hero_pos == actual_pos && fight_result == 9) {
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
