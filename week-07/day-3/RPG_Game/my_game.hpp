#pragma once
#include "game-engine-2.hpp"
#include "character.hpp"
#include "level_builder.hpp"
#include "recursive_level.hpp"
#include "square_level.hpp"
#include "enemy.hpp"
#include "enemy_calling.hpp"
#include "treasure.hpp"
#include "welcome_srceen.hpp"
#include "score.hpp"

class my_game : public Game {
private:
  level_builder* level;
  character hero;
  enemy snake;
  enemy_calling enemies;
  treasure arch;
  welcome_srceen welcome;
  score my_score;
public:
  my_game();
  ~my_game();
  void init(GameContext&);
  void render(GameContext&);
  void render_welcome(GameContext&);
  void test_to_command_line();
};