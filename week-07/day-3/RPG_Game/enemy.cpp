#include "enemy.hpp"

enemy::enemy(level_builder &in_level) {
  this->level = &in_level;
}

enemy::enemy() {

}

enemy::~enemy() {
}



std::string enemy::get_enemy_pic_path() {
  return this->enemy_pic_path;
}

void enemy::print_level_map(level_builder &level) {
  for (int i = 0; i < level.get_map_size(); i++) {
    for (int j = 0; j < level.get_map_size(); j++) {
      std::cout << level.get_map(i, j) << ' ';
    }
    std::cout << std::endl;
  }
}
