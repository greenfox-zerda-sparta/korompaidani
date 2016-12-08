#pragma once
#include "game-engine-2.hpp"

class level_builder {
private:
  std::string wall_pic_dir;
  std::string floor_pic_dir;
protected:
  int map_size;
  std::vector<std::vector<int>> map;
public:
  level_builder();
  ~level_builder();

  std::string get_wall_pic_dir();
  std::string get_floor_pic_dir();

  void level_creator(GameContext&);
};
