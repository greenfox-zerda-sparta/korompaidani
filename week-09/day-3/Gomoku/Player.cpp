#include "Player.hpp"

Player::Player(std::string name1) {
  this->name = name1;
}

Player::Player(std::string name1, Player& player_2) {
  this->name = name1;
  player_num = 1;
}

std::string Player::get_name() {
  return this->name;
}

