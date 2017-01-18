#ifndef SDLWINDOW_H_
#define SDLWINDOW_H_

#include <utility>
#include <vector>
#include "SDL.h"

using namespace std;

class SDL_Window {
private:
  int x;
  int y;
  int gamer = 1;
  SDL_Window *window;
  SDL_Renderer* renderer;
  SDL_Surface * image;
  SDL_Texture * texture;
  SDL_Event event;
public:
  SDL_Window(int, int);
  void run();
  pair <int, int> create_click_coordinates(int x, int y);
  void drawbackground();
  void drawimage(int & x, int& y, int &gamer);
  ~SDL_Window();
};

#endif /* SDLWINDOW_H_ */