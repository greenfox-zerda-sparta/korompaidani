#pragma once
#include "game-engine-2.hpp"

class my_game : public Game {
private:
  std::vector<std::vector<int>> map;
  int map_size;
  int frame_size;
  int shift;
  std::vector<std::vector<int>> player_path;
public:
  my_game();
  ~my_game();
  void init(GameContext&);// itt kell hivni a bool keypressedet mert az a gamecontexten belul van, amit lat a my gamem
  void render(GameContext&);
  void square_drawer();
  void reqursive_drawer(int, int, int);
};