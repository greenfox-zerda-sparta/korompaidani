#pragma once
#include "game-engine-2.hpp"
#include "level_builder.hpp"

class enemy {
private:
  std::vector<std::vector<int>> location;
  std::string enemy_pic_path;
  level_builder* level;
  int coord_x;
  int coord_y;
public:
  enemy(level_builder&);
  enemy();
  ~enemy();

  std::string get_enemy_pic_path();
  void print_level_map(level_builder&);
};

