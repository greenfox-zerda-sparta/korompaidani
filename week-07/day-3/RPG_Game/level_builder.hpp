#pragma once
#include "game-engine-2.hpp"

class level_builder {
private:
  int map_size;
  int frame_size;
  int shift;
protected:
  std::vector<std::vector<int>> map;
public:
  level_builder();
  ~level_builder();
  void square_drawer();
  void level_creator(GameContext&);
};

