#include "enemy_calling.hpp"



enemy_calling::enemy_calling() {
}

enemy_calling::~enemy_calling() {
}

void enemy_calling::call_enemies(GameContext &context, level_builder &level, character &hero) {
  e1.set_enemy_picture('s');
  e1.enemy_appear(context, level);
  e1.enemy_death(hero.character_fight(context), hero.get_actual_pos());
  e2.set_enemy_picture('s');
  e2.enemy_appear(context, level);
  e2.enemy_death(hero.character_fight(context), hero.get_actual_pos());
  e3.set_enemy_picture('s');
  e3.enemy_appear(context, level);
  e3.enemy_death(hero.character_fight(context), hero.get_actual_pos());
  e4.set_enemy_picture('m');
  e4.enemy_appear(context, level);
  e4.enemy_death(hero.character_fight(context), hero.get_actual_pos());
  e5.set_enemy_picture('m');
  e5.enemy_appear(context, level);
  e5.enemy_death(hero.character_fight(context), hero.get_actual_pos());
  e6.set_enemy_picture('m');
  e6.enemy_appear(context, level);
  e6.enemy_death(hero.character_fight(context), hero.get_actual_pos());
}
