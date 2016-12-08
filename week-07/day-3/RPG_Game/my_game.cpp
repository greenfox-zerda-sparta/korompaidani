#include "my_game.hpp"

my_game::my_game() {
  this->level = new recursive_level;
  this->level->drawer(0, 0, 0);
  this->level->get_map(0, 1);
};

my_game::~my_game() {
};

void my_game::init(GameContext& context) {
  context.load_file(level->get_floor_pic_path());
  context.load_file(level->get_wall_pic_path());
  context.load_file(skeleton.get_enemy_pic_path());
  context.load_file(hero.get_character_pic_path('d'));
  context.load_file(hero.get_character_pic_path('u'));
  context.load_file(hero.get_character_pic_path('l'));
  context.load_file(hero.get_character_pic_path('r'));
};

void my_game::render(GameContext& context) {
  level->level_creator(context);
  skeleton.enemy_appear(context, *level);
  hero.character_walk(context, *level);
  skeleton.enemy_death(hero.character_fight(context), hero.get_actual_pos());
  context.render();

  std::cout << "hero act pos = " << hero.get_actual_pos() << std::endl;
  std::cout << "skel act pos = " << skeleton.get_actual_pos() << std::endl;
};