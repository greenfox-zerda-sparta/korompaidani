#pragma once

#include "SDLWindow.hpp"
#include "Player.hpp"
#include "Scan.hpp"
#include "Map.hpp"
#include "Client_cl.hpp"
#include "Server_sr.hpp"

class my_game {
private:
  Map* my_map;
  Player* player_1;
  Player* player_2;
  Scan* scan;
  SDL_Window* sdl_window;
  std::string player_1_name;
  std::string player_2_name;
  Client_cl my_client;
  Server_sr my_server;
  unsigned short int screen_size;
  unsigned short int map_size;
public:
  my_game(std::string, std::string, unsigned short int, unsigned short int, Client_cl&, Server_sr&);
  ~my_game();
  void game_handler();
  void launch();
  void print_map_vector();
};