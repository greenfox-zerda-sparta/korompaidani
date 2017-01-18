#include "SDL.h"
#include "Color.hpp"
#include <iostream>

SDL_Window *window;

int main(int argc, char* argv[]) {

  Color c1(51, 204, 51);
  Color c2("#4999dd");

  std::cout << (int)*c2.get_red() << std::endl;
  std::cout << (int)*c2.get_green() << std::endl;
  std::cout << (int)*c2.get_blue() << std::endl << std::endl;

  /*c2.make_negative();
  std::cout << (int)*c2.get_red() << std::endl;
  std::cout << (int)*c2.get_green() << std::endl;
  std::cout << (int)*c2.get_blue() << std::endl << std::endl;*/

  //c2.blend(c1);

  std::cout << "lighten" << std::endl;
  c2.lighten_10();
  std::cout << (int)*c2.get_red() << std::endl;
  std::cout << (int)*c2.get_green() << std::endl;
  std::cout << (int)*c2.get_blue() << std::endl << std::endl;
  c2.lighten_10();
  std::cout << (int)*c2.get_red() << std::endl;
  std::cout << (int)*c2.get_green() << std::endl;
  std::cout << (int)*c2.get_blue() << std::endl << std::endl;
  c2.lighten_10();
  std::cout << (int)*c2.get_red() << std::endl;
  std::cout << (int)*c2.get_green() << std::endl;
  std::cout << (int)*c2.get_blue() << std::endl << std::endl;
  c2.lighten_10();
  std::cout << (int)*c2.get_red() << std::endl;
  std::cout << (int)*c2.get_green() << std::endl;
  std::cout << (int)*c2.get_blue() << std::endl << std::endl;

  SDL_Window* window;
  SDL_Renderer* renderer;
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    return 1;
  }
  window = SDL_CreateWindow("SDL_RenderClear", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 200, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, *c2.get_red(), *c2.get_green(), *c2.get_blue(), 0);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  SDL_Delay(5000);
  SDL_Quit();
  return 0;
}

/*unsigned char col = 7;
int valami = col;
int* valami_ptr = &valami;
std::cout << *valami_ptr;*/