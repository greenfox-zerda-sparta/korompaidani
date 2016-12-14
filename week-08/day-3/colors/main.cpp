#include "SDL.h"
#include "Color.hpp"

SDL_Window *window;

int main(int argc, char* argv[]) {
  SDL_Window* window;
  SDL_Renderer* renderer;
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    return 1;
  }
  window = SDL_CreateWindow("SDL_RenderClear", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  SDL_Delay(5000);
  SDL_Quit();
  return 0;
}