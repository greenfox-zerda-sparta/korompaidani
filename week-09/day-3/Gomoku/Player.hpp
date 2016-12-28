#pragma once
#include "ERROR_CODES.hpp"
#include "Map.hpp"
#include <string>
#include <utility>

class Player {
private:
  std::string name;
  unsigned short int player_num;
  std::pair <int, int> last_click_coordinates;
public:
  Player(std::string);
  Player(std::string, Player&);
  std::string get_name();
  unsigned short int get_player_num();
  bool choise(Map&, unsigned short int, unsigned short int);
  void set_last_click_coordinates(int, int);
  std::pair <int, int> get_last_click_coordinates();
};

