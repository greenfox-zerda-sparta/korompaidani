#pragma once
#include "game-engine-2.hpp"

class character {
private:
  std::string hero_pic_dir;
  int coord_x;
  int coord_y;
public:
  character();
  ~character();
  void hero_walk(GameContext&);
};

