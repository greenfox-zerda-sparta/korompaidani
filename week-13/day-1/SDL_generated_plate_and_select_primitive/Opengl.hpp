#pragma once
#include <iostream>
#include <Windows.h>
#include "SDL.h"
#include <glut.h>

#include "Map.hpp"
#include <iostream>

class Opengl {
private:
  SDL_Window *screen;
  Map quad_map;
public:
  Opengl();
  ~Opengl();
  void opengl_init(int, int);
  void opengl_sreenbuilder();
  void opengl_display();
  void pick_objects(int button, int state, int x, int y);
  void display_objects(void);
};

