#pragma once

#include "draw.h"

class my_draw : public draw {
private:
  double main_shift_w = 0;
  double main_shift_h = 0;
  double plus_shift_w;
  double plus_shift_h;
public:
  ~my_draw();
  int rectangle(SDL_Renderer* &renderer, int, int, int, int);
  int triangle(SDL_Renderer* &renderer, int, int, int, int);
  int triangle2(SDL_Renderer* &renderer, int, int, int);
  void my_drawer(SDL_Renderer* &renderer, int, int);
  };