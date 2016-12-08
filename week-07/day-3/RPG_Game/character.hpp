#pragma once
#include "game-engine-2.hpp"

class character {
private:
  std::string character_pic_dir;
  int coord_x;
  int coord_y;
public:
  character();
  ~character();

  std::string get_character_pic_dir();

  void hero_walk(GameContext&);
};

