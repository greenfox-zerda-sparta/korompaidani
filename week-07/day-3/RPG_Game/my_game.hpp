#pragma once
#include "game-engine-2.hpp"
#include "character.hpp"
#include "level_builder.hpp"
#include "recursive_level.hpp"
#include "square_level.hpp"
#include "enemy.hpp"

class my_game : public Game {
private:
  level_builder* level;
  character hero;
  enemy skeleton;
public:
  my_game();
  ~my_game();
  void init(GameContext&);
  void render(GameContext&);
};