#include "my_draw.hpp"

my_draw::~my_draw() {
}

int my_draw::rectangle(SDL_Renderer *& renderer, int width, int height, int shift_w, int shift_h) {
  MoveTo(shift_w, shift_h);
  DrawTo(renderer, (width - (width * (double)1)) + shift_w, (height - (height * (double)2 / 3)) + shift_h);
  DrawTo(renderer, (width - (width * (double)2 / 3)) + shift_w, (height - (height * (double)2 / 3)) + shift_h);
  DrawTo(renderer, (width - (width * (double)2 / 3)) + shift_w, (height - (height * (double)1)) + shift_h);
  DrawTo(renderer, (width - (width * (double)1)) + shift_w, (height - (height * (double)1)) + shift_h);
  width /= 3;
  height /= 3;
  if (width < 1) {
    return 0;
  }
  else {
   rectangle(renderer, width, height, width * (double)1, height * (double)2 / 3);
   rectangle(renderer, width, height, width * (double)2 / 3, height * (double)2 / 3);
   rectangle(renderer, width, height, width * (double)2 / 3, height * (double)1);
   rectangle(renderer, width, height, width * (double)1, height * (double)1);
  }
}

int my_draw::plus_operator(SDL_Renderer *& renderer, int width, int height, double p_shift_w, double p_shift_h) {
  if (width < 1) {
    return 0;
  }
  else {
    rectangle(renderer, width, height, width * (double)2 / 3 + p_shift_w, height * (double)1 / 3 + p_shift_h);
    rectangle(renderer, width, height, width * (double)1 / 3 + p_shift_w, height * (double)2 / 3 + p_shift_h);
    rectangle(renderer, width, height, width * (double)1 / 3 + p_shift_w, height * (double)0 + p_shift_h);
    rectangle(renderer, width, height, width * (double)0 + p_shift_w, height * (double)1 / 3 + p_shift_h);
    return plus_operator(renderer, (double)width / 3, (double)height / 3, width * (double)2 / 3, height * (double)2 / 3);
  }
}

void my_draw::recursive(SDL_Renderer *& renderer, int width, int height, double p_shift_w, double p_shift_h) {
  for (int i = 0; i < 4; i++) {
    if (i == 0) {
      plus_shift_w = ((double)2 / 3) / 3;
      plus_shift_h = ((double)1 / 3) / 3;
    }
    else if (i == 1) {
      plus_shift_w = ((double)1 / 3) / 3;
      plus_shift_h = ((double)2 / 3) / 3;
    }
    else if (i == 2) {
      plus_shift_w = ((double)1 / 3) / 3;
      plus_shift_h = 0;
    }
    else if (i == 3) {
      plus_shift_w = 0;
      plus_shift_h = ((double)1 / 3) / 3;
    }
    plus_operator(renderer, width / 3, height / 3, width * plus_shift_w, height * plus_shift_h);
  }
}

void my_draw::my_drawer(SDL_Renderer* &renderer, int width, int height) {
 // recursive(renderer, width, height, 0, 0);
 // plus_operator(renderer, width, height, 0, 0);
  rectangle(renderer, width, height, width / 3, 0);
}
