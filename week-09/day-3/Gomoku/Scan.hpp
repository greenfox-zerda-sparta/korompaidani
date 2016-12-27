#pragma once
#include "ERROR_CODES.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include <utility>
#include <iostream>

class Scan {
private:
  std::pair<char, int> win_case;
  unsigned short int win_player_num;
public:
  Scan();
  bool horizontal(Map&);
  bool vertical(Map&);
  void round_scan(Map&);
  std::pair<char, int> get_win_case();
  unsigned short int get_win_player_num();
};

