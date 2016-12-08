#include "my_game.hpp"

my_game::my_game() {
  level = new recursive_level;
  level->drawer(0, 0, 0);
  level->get_map(0, 1);
};

my_game::~my_game() {
};

void my_game::init(GameContext& context) {
  context.load_file(level->get_floor_pic_dir());
  context.load_file(level->get_wall_pic_dir());
  context.load_file(hero.get_character_pic_down_dir());
};

void my_game::render(GameContext& context) {
  level->level_creator(context);
  hero.character_walk(context, *level);
  context.render();
};