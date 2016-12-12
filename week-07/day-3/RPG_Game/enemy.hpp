#pragma once
#include "game-engine-2.hpp"
#include "level_builder.hpp"
#include <ctime>

class enemy {
private:
  std::vector<std::vector<int>> location;
  std::string enemy_pic_path;
  std::string enemy_pic_down_path;
  std::string enemy_pic_up_path;
  std::string enemy_pic_left_path;
  std::string enemy_pic_right_path;
  char choosen_direction;
  level_builder* level;
  int coord_x;
  int coord_y;
  int actual_pos;
  int enemy_hp_counter;
  int death_counter;
  unsigned short int pulse;
  const int MOVING_SPEED;
public:
  enemy();
  ~enemy();

  std::string get_enemy_pic_path(char);
  int get_actual_pos();
  int get_death_counter();
  void enemy_appear(GameContext&, level_builder&);
  void enemy_walk(GameContext&, level_builder&);
  void enemy_death(int, int);
  void print_level_map(level_builder&);
  int increase_pulse();
};