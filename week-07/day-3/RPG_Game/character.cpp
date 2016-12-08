#include "character.hpp"

character::character() {
  character_pic_down_dir = "pics/hero-down.bmp";
  int coord_x = 0;
  int coord_y = 0;
}

character::~character() {
}

std::string character::get_character_pic_down_dir() {
  return character_pic_down_dir;
}

void character::character_walk(GameContext &context, level_builder &level) {
  context.draw_sprite(character_pic_down_dir, coord_x, coord_y);
  if (context.was_key_pressed(ARROW_DOWN) == true) {
    coord_y += 72;
  }
  context.draw_sprite("pics/hero-down.bmp", coord_x, coord_y);
  context.reset_keys();
}
