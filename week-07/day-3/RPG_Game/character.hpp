#pragma once
#include "game-engine-2.hpp"
#include "level_builder.hpp"

class character {
private:
  std::string character_pic_down_dir;
  int coord_x;
  int coord_y;
public:
  character();
  ~character();

  std::string get_character_pic_down_dir();

  void character_walk(GameContext&, level_builder&);
};

