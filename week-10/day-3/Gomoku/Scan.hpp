#pragma once
#include "ERROR_CODES.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include <utility>
#include <iostream>

struct borders {
  int right = 0;
  int left = 0;
  int top = 0;
  int bottom = 0;
};

class Scan {
private:
  unsigned short int win_player_num;
public:
  Scan();
  bool vertical(Map&, std::pair<int, int>, int);
  bool horizontal(Map&, std::pair<int, int>, int);
  bool diagonal_se(Map&, std::pair<int, int>, int);
  bool diagonal_nw(Map&, std::pair<int, int>, int);
  bool diagonal_sw(Map&, std::pair<int, int>, int);
  bool diagonal_ne(Map&, std::pair<int, int>, int);
  void round_scan(Map&, std::pair<int, int>, int);
  unsigned short int get_win_player_num();
  void reset_win_player_num();
};

