#pragma once
#include <SDL.h>
//#include "draw.h"
#include "my_draw.hpp"

class my_engine {
private:
  int width;
  int height;
  int Red;
  int Green;
  int Blue;
  SDL_Renderer* renderer;
  SDL_Window* window;
  my_draw* canvas;
  bool quit;
  SDL_Event event;
public:
  my_engine(my_draw*);
  ~my_engine();
  void init();
  void window_handler();
  void render(SDL_Renderer*);
  void window_close();
  void run();

};

