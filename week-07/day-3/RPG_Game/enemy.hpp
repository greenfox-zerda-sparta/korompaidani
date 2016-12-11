#pragma once
#include "game-engine-2.hpp"
#include "level_builder.hpp"
#include <ctime>

class enemy {
private:
  std::vector<std::vector<int>> location;
  std::string enemy_pic_path;
  level_builder* level;
  int coord_x;
  int coord_y;
  int actual_pos;
  int enemy_hp_counter;
  int death_counter;
  unsigned short int pulse;
  const int MOVING_SPEED;
public:
  enemy(level_builder&);
  enemy();
  ~enemy();

  std::string get_enemy_pic_path();
  int get_actual_pos();
  int get_death_counter();
  void enemy_appear_and_walk(GameContext&, level_builder&);
  void enemy_death(int, int);
  void print_level_map(level_builder&);
  int increase_pulse();
};