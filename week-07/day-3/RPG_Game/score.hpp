#pragma once
#include "game-engine-2.hpp"
#include "enemy.hpp"
#include "treasure.hpp"
#include <sstream>

class score {
private:  
  int enemy_death_counter;
  int treasure_catch_counter;
  std::string score_content;
public:
  score();
  ~score();
  void fill_score(int, int);
  std::string int_to_string(int);
  std::string get_score_content();
};

