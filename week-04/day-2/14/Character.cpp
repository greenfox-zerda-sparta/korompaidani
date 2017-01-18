#include <iostream>
#include <string>
#include <cstdlib>
#include "Character.h"
#include <ctime>

using namespace std;

Character::Character(string in_name, char in_type) {
  name = in_name;
  switch (in_type) {
    case 'p':
      this->character_type = in_type;
      this->defense = 3;
      this->attack = 4;
      break;
    case 'm':
      this->character_type = in_type;
      this->defense = 3;
      this->attack = 4;
      break;
    default:
      this->character_type = 'm';
  }
};

void Character::set_health(int value) {
  this->health += value;
};

string Character::get_name() {
  return name;
};
int Character::get_health() {
  return health;
};
int Character::get_attack() {
  return attack;
};
int Character::get_defense() {
  return defense;
};

int Character::attack_calc() {
  int poss = rand() % 2 + 1;
  if (poss == 1) {
    return -1;
  }
  else {
    return 1;
  }
};

void Character::attack_act(Character& enemy) {
  int att_score = attack_calc() * attack;
  if (att_score > enemy.get_defense()) {
    enemy.set_health(-1);
  }
  else if (att_score < enemy.get_defense()) {
    set_health(-1);
  }
  else {
    cout << "Nobody got hurt";
  }
  srand(time(NULL));
};

