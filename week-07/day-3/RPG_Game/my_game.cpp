#include "my_game.hpp"

my_game::my_game() {
  rec_level.recursive_drawer(0, 0, 0);
};

my_game::~my_game() {
};

void my_game::init(GameContext& context) {
  context.load_file("pics/floor.bmp");
  context.load_file("pics/wall.bmp");
  context.load_file("pics/hero-down.bmp");
};

void my_game::render(GameContext& context) {
  rec_level.level_creator(context);
  hero.hero_walk(context);
  context.render();
};