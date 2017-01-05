#ifndef SDLWINDOW_H_
#define SDLWINDOW_H_

#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include "SDL.h"
#include "Player.hpp"
#include "Scan.hpp"
#include "ERROR_CODES.hpp"
#include "Client_cl.hpp"
#include "Server_sr.hpp"

using namespace std;

class SDL_Window {
private:
  int width;
  int height;
  int tile_size;
  int map_size;
  char* board_image;
  char* o_image;
  char* x_image;
  char* x_win_image;
  char* o_win_image;
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Surface* image;
  SDL_Texture* texture;
  SDL_Event event;
  std::map<std::string, SDL_Texture*> sprites;
  SDL_Window* screen;
public:
  SDL_Window(int, int, int);
  void create_window();
  void create_win_window();
  void run(Map&, Player&, Player&, Scan&, Client_cl&, Server_sr&);
  bool game_logic_as_client(Map&, Player&, Scan&, bool&, Client_cl&);
  bool game_logic_as_server(Map&, Player&, Scan&, bool&, Server_sr&);
  void drawbackground();
  void drawimage(int&, int&, int);
  void fill_image_by_tile(int);
  void draw_full_size_image(int);
  ~SDL_Window();
};

#endif