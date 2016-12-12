#pragma once
#include "enemy.hpp"
#include "game-engine-2.hpp"
#include "level_builder.hpp"
#include "character.hpp"

class enemy_calling {
public:
  enemy e1;
  enemy e2;
  enemy e3;
  enemy e4;
  enemy e5;
  enemy e6;
  enemy_calling();
  ~enemy_calling();
  void call_enemies(GameContext&, level_builder&, character&);
};

