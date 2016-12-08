#pragma once
#include "game-engine-2.hpp"

class level_builder {
private:
  std::string wall_pic_path;
  std::string floor_pic_path;
protected:
  int map_size;
  std::vector<std::vector<int>> map;
public:
  level_builder();
  ~level_builder();

  std::string get_wall_pic_path();
  std::string get_floor_pic_path();
  int get_map_size();
  int get_map(int, int);

  virtual void drawer(int, int, int);
  void level_creator(GameContext&);
};
