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
  MoveTo(shift_w, shift_h);
  DrawTo(renderer, (width - (width * (double)1)) + shift_w, (height - (height * (double)2 / 3)) + shift_h);
  DrawTo(renderer, (width - (width * (double)2 / 3)) + shift_w, (height - (height * (double)2 / 3)) + shift_h);
  DrawTo(renderer, (width - (width * (double)2 / 3)) + shift_w, (height - (height * (double)1)) + shift_h);
  DrawTo(renderer, (width - (width * (double)1)) + shift_w, (height - (height * (double)1)) + shift_h);
}

void my_draw::plus_operator(SDL_Renderer *& renderer, int width, int height, int p_shift_w, int p_shift_h) {
  rectangle(renderer, width, height, p_shift_w + width / 3, p_shift_h + height - height);
  rectangle(renderer, width, height, p_shift_w + width - width, p_shift_h + height / 3);
  rectangle(renderer, width, height, p_shift_w + width / 3, p_shift_h + height * (double)2 / 3);
  rectangle(renderer, width, height, p_shift_w + width * (double)2 / 3, p_shift_h + height / 3);
}

void my_draw::recursive(SDL_Renderer *& renderer, int width, int height, int p_shift_w, int p_shift_h) {
  plus_operator(renderer, width, height, p_shift_w, p_shift_h);
}

void my_draw::my_drawer(SDL_Renderer* &renderer, int width, int height) {
  recursive(renderer, width, height, 10, 10);
}
