#pragma once

#include "draw.h"

class my_draw : public draw {
public:
  ~my_draw();
  int fibonacci(int);
  void rectangle(SDL_Renderer* &renderer, int, int, int, int);
  void plus_operator(SDL_Renderer* &renderer, int, int);
  void my_drawer(SDL_Renderer* &renderer, int, int);
};