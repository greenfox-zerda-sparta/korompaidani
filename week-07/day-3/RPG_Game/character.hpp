#pragma once
#include "game-engine-2.hpp"
#include "level_builder.hpp"

class character {
private:
  int map_size;
  std::vector<std::vector<int>> location;
  std::string character_pic_down_path;
  std::string character_pic_up_path;
  std::string character_pic_left_path;
  std::string character_pic_right_path;
  char choosen_direction;
  int coord_x;
  int coord_y;
  int actual_pos;
public:
  character();
  ~character();

  void set_map_size(int);
  std::string get_character_pic_path(char);
  int get_actual_pos();
  void character_walk(GameContext&, level_builder&);
  int character_fight(GameContext&);
};

