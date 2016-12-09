#include "welcome_srceen.hpp"

welcome_srceen::welcome_srceen() {
  welcome_srceen_path = "pics/welcome.bmp";
  key_was_pressed = false;
}

welcome_srceen::~welcome_srceen() {
}

std::string welcome_srceen::get_welcome_srceen_path() {
  return welcome_srceen_path;
}

void welcome_srceen::appear(GameContext &context) {
  if (context.was_key_pressed(SPACE) == true && key_was_pressed == false) {
    context.draw_sprite(get_welcome_srceen_path(), 72, 72);
    key_was_pressed = true;
  }
}
