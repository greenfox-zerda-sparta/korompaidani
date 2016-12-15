#include "my_engine.hpp"

my_engine::my_engine(draw* in_draw) {
  this->width = 640;
  this->height = 480;
  this->quit = false;
  this->canvas = in_draw;
}

my_engine::~my_engine() {
}

void my_engine::init() {
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow("SDL2 Fractal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
}

void my_engine::window_handler() {
  while (!quit) {
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    render(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
  }
}

void my_engine::render(SDL_Renderer* r) {
  canvas->DrawTo(r, 200, 400);
  canvas->DrawBy(r, 90);
}

void my_engine::window_close() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void my_engine::run() {
  init();
  window_handler();
  window_close();
}