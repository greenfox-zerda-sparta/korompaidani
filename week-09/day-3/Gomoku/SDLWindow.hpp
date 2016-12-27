#ifndef SDLWINDOW_H_
#define SDLWINDOW_H_

#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include "SDL.h"
#include "player.hpp"
#include "ERROR_CODES.hpp"

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
  pair <int, int> click_coordinates;
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
  void run(Map&, Player&, Player&);
  bool game_logic(Map&, Player&);
  pair <int, int> get_click_coordinates();
  void drawbackground();
  void drawimage(int&, int&, int);
  void fill_image_by_tile(int);
  void draw_full_size_image(int);
  ~SDL_Window();
};

#endif