#pragma once
#include "game-engine-2.hpp"
#include "level_builder.hpp"

class treasure {
private:
  std::vector<std::vector<int>> location;
  std::string treasure_pic_path;
  level_builder* level;
  int coord_x;
  int coord_y;
  int actual_pos;
  int treasure_catch_checker;
  int catch_counter;
public:
  treasure();
  ~treasure();

  std::string get_treasure_pic_path();
  int get_catch_counter();
  int get_actual_pos();
  void appear(GameContext&, level_builder&);
  void picked_up(int, int);
};

