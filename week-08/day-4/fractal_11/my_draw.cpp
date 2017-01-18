#include "my_draw.hpp"

my_draw::~my_draw() {
}

int my_draw::rectangle(SDL_Renderer *& renderer, int width, int height, int shift_w, int shift_h) {
  int step = (width - shift_w) / 3;
  MoveTo(shift_w + step, shift_h);
  DrawTo(renderer, shift_w + step, height);
  MoveTo(width - step, shift_h);
  DrawTo(renderer, width - step, height);
  MoveTo(shift_w, shift_h + step);
  DrawTo(renderer, width, shift_h + step);
  MoveTo(shift_w, height - step);
  DrawTo(renderer, width, height - step);
  if (step > 6) {
    rectangle(renderer, width - step, shift_h + step, shift_w + step, shift_h);
    rectangle(renderer, shift_w + step, height - step, shift_w, shift_h + step);
    rectangle(renderer, width, height - step, width - step, shift_h + step);
    rectangle(renderer, width - step, height, shift_w + step, height - step);
  }
  return 0;
}

int my_draw::triangle(SDL_Renderer *& renderer, int width, int height, int shift_w, int shift_h) {
  int step = (width - shift_w) / 2;

  MoveTo(width / 2, height);
  DrawTo(renderer, width + shift_w, height - height + shift_h);
  MoveTo(width / 2, height);
  DrawTo(renderer, width - width + shift_w, height - height + shift_h);
  //DrawTo(renderer, width - width + shift_w, height - height + shift_h);
  //DrawTo(renderer, width / 2 + shift_w, height + shift_h);
  if (step > 6) {
    width /= 2;
    height /= 2;
    triangle(renderer, width, height, shift_w, shift_h);
    triangle(renderer, width, height, shift_w, shift_h);
  }
  return 0;
}

int my_draw::triangle2(SDL_Renderer *& renderer, int length, int start_w, int start_h) {
  MoveTo(start_w + length / 2, start_h);
  TurnBy(60);
  DrawBy(renderer, length);
  TurnBy(60);
  DrawBy(renderer, length);
  TurnBy(300);
  DrawBy(renderer, length);

  /*
  MoveTo(a_w, a_h);
  DrawTo(renderer, b_w, b_h);
  DrawTo(renderer, c_w, c_h);
  DrawTo(renderer, a_w, a_h);
  */
  if (length > 3) {
    triangle2(renderer, length / 2, start_w, start_h);
  }
  return 0;
}

void my_draw::my_drawer(SDL_Renderer* &renderer, int width, int height) {
  ///rectangle(renderer, width, height, 0, 0);
  //triangle(renderer, width, height, 0, 0);
  triangle2(renderer, width, 0, 0);
}