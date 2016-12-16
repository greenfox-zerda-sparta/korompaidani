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
  DrawTo(renderer, (width - (width * (double)1)) + shift_w, (height - (height * (double)1)) + shift_h);
  DrawTo(renderer, (width - (width * (double)1)) + shift_w, (height - (height * (double)2 / 3)) + shift_h);
  DrawTo(renderer, (width - (width * (double)2 / 3)) + shift_w, (height - (height * (double)2 / 3)) + shift_h);
  DrawTo(renderer, (width - (width * (double)2 / 3)) + shift_w, (height - (height * (double)1)) + shift_h);
  DrawTo(renderer, (width - (width * (double)1)) + shift_w, (height - (height * (double)1)) + shift_h);
}

void my_draw::plus_operator(SDL_Renderer *& renderer, int width, int height) {
  rectangle(renderer, width, height, width / 3, height - height);
  rectangle(renderer, width, height, width - width, height / 3);
  rectangle(renderer, width, height, width / 3, height * (double)2 / 3);
  rectangle(renderer, width, height, width * (double)2 / 3, height / 3);

  width = width / 3;
  height = height / 3;

  rectangle(renderer, width, height, width / 3, height - height);
  rectangle(renderer, width, height, width - width, height / 3);
  rectangle(renderer, width, height, width / 3, height * (double)2 / 3);
  rectangle(renderer, width, height, width * (double)2 / 3, height / 3);

  width = width / 3;
  height = height / 3;

  rectangle(renderer, width, height, width / 3, height - height);
  rectangle(renderer, width, height, width - width, height / 3);
  rectangle(renderer, width, height, width / 3, height * (double)2 / 3);
  rectangle(renderer, width, height, width * (double)2 / 3, height / 3);

  width = width / 3;
  height = height / 3;

  rectangle(renderer, width, height, width / 3, height - height);
  rectangle(renderer, width, height, width - width, height / 3);
  rectangle(renderer, width, height, width / 3, height * (double)2 / 3);
  rectangle(renderer, width, height, width * (double)2 / 3, height / 3);
}

void my_draw::my_drawer(SDL_Renderer* &renderer, int width, int height) {
  plus_operator(renderer, width, height);
}
