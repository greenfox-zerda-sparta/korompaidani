#pragma once
#include "game-engine-2.hpp"
#include "character.hpp"
#include "level_builder.hpp"
#include "recursive_level.hpp"

class my_game : public Game {
private:
  recursive_level rec_level;
  character hero;
public:
  my_game();
  ~my_game();
  void init(GameContext&);
  void render(GameContext&);
};