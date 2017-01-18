#include "my_game.hpp"

my_game::my_game() {
  this->level = new recursive_level;
  this->level->drawer(0, 0, 0);
  this->level->get_map(0, 1);
  my_score.fill_score(snake.get_death_counter(), arch.get_catch_counter());
};

my_game::~my_game() {
};

void my_game::init(GameContext& context) {
  context.load_file(welcome.get_welcome_srceen_path());
  context.load_file(level->get_floor_pic_path());
  context.load_file(level->get_wall_pic_path());
  context.load_file("pics/snake-down.bmp");
  context.load_file("pics/snake-up.bmp");
  context.load_file("pics/snake-left.bmp");
  context.load_file("pics/snake-right.bmp");
  context.load_file("pics/molaram-down.bmp");
  context.load_file("pics/molaram-up.bmp");
  context.load_file("pics/molaram-left.bmp");
  context.load_file("pics/molaram-right.bmp");
  context.load_file("pics/soldier-down.bmp");
  context.load_file("pics/soldier-up.bmp");
  context.load_file("pics/soldier-left.bmp");
  context.load_file("pics/soldier-right.bmp");
  context.load_file(arch.get_treasure_pic_path());
  context.load_file(hero.get_character_pic_path('d'));
  context.load_file(hero.get_character_pic_path('u'));
  context.load_file(hero.get_character_pic_path('l'));
  context.load_file(hero.get_character_pic_path('r'));
};

void my_game::render(GameContext& context) {
  level->level_creator(context);
  arch.appear(context, *level);
  
  enemies.call_enemies(context, *level, hero);
  hero.character_walk(context, *level);
  arch.picked_up(hero.character_fight(context), hero.get_actual_pos());
  context.render();
}
void my_game::render_welcome(GameContext& context) {
  ///welcome.appear(context);
  render(context);

}

void my_game::test_to_command_line() {
  std::cout << my_score.get_score_content() << std::endl;
}