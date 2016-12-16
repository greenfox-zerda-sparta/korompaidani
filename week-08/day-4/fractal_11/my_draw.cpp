#include "my_draw.hpp"

my_draw::~my_draw() {
}

int my_draw::fibonacci(int n) {
  if ((0 == n) || (1 == n)) {
    return n;
  }
  else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

void my_draw::rectangle(SDL_Renderer *& renderer, int width, int height, int shift_w, int shift_h) {
  //DrawBy(renderer, width * ((double)1 / 3));
  DrawTo(renderer, (width * ((double)1)) + shift_w, (height * ((double)1)) + shift_h); // 1 1
  DrawTo(renderer, (width * ((double)1)) + shift_w, (height * ((double)2 / 3)) + shift_h); // 1 1/3 
  DrawTo(renderer, (width * ((double)2 / 3)) + shift_w, (height * ((double)2 / 3)) + shift_h); // 1/3 1/3
  DrawTo(renderer, (width * ((double)2 / 3)) + shift_w, (height * ((double)1)) + shift_h); // 1/3 1
}

void my_draw::plus_operator(SDL_Renderer *& renderer, int width, int height) {
  rectangle(renderer, width, height, -(width * ((double)1 / 3)), -(height * ((double)1 / 3)));
}

void my_draw::my_drawer(SDL_Renderer* &renderer, int width, int height) {
  plus_operator(renderer, width, height);
}
