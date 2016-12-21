#include "Player.hpp"

Player::Player(std::string name1) {
  this->name = name1;
  player_num = 1;
}

Player::Player(std::string name1, Player& player_other) {
  this->name = name1;
  if (player_other.get_player_num() == 1) {
    this->player_num = 2;
  }
  else {
    this->player_num = 1;
  }
}

std::string Player::get_name() {
  return this->name;
}

unsigned short int Player::get_player_num() {
  return this->player_num;
}
