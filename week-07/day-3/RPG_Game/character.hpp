#pragma once
#include "game-engine-2.hpp"
#include "level_builder.hpp"

class character {
private:
  std::vector<std::vector<int>> location;
  std::string character_pic_down_path;
  std::string character_pic_up_path;
  std::string character_pic_left_path;
  std::string character_pic_right_path;
  char choosen_direction;
  int coord_x;
  int coord_y;
public:
  character();
  ~character();

  std::string get_character_pic_path(char);
  void character_walk(GameContext&, level_builder&);
};
