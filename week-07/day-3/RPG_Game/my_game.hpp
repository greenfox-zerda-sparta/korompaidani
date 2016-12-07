#pragma once
#include "game-engine-2.hpp"

class my_game : public Game {
private:
  std::vector<std::vector<int>> map;
public:
  my_game();
  ~my_game();
  void init(GameContext&);
  void render(GameContext&);
};