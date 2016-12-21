#pragma once
#include "Map.hpp"
#include "ERROR_CODES.hpp"
#include <string>

class Player {
private:
  std::string name;
  unsigned short int player_num;
public:
  Player(std::string);
  Player(std::string, Player&);
  std::string get_name();
  unsigned short int get_player_num();
};

