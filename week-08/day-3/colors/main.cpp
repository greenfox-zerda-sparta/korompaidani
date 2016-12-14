#include "SDL.h"
#include "Color.hpp"
#include <iostream>

SDL_Window *window;

int main(int argc, char* argv[]) {

  Color c(88, 20, 200);
  unsigned char col = 7;
  int valami = col;
  int* valami_ptr = &valami;
  std::cout << *valami_ptr;

  SDL_Window* window;
  SDL_Renderer* renderer;
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    return 1;
  }
  window = SDL_CreateWindow("SDL_RenderClear", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 200, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, *c.get_red(), *c.get_green(), *c.get_blue(), 0);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  SDL_Delay(5000);
  SDL_Quit();
  return 0;
}