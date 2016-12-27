#pragma once

#include "SDLWindow.hpp"
#include "player.hpp"
#include "scan.hpp"
#include "map.hpp"

class my_game {
private:
  Map* my_map;
  Player* player_1;
  Player* player_2;
  SDL_Window* sdl_window;
  std::string player_1_name;
  std::string player_2_name;
  unsigned short int screen_size;
  unsigned short int map_size;
public:
  my_game(std::string, std::string, unsigned short int, unsigned short int);
  ~my_game();
  void game_handler();
  void launch();
  void print_map_vector();
};