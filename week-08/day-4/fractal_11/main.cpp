#include <iostream>
#include "draw.h"
#include "my_draw.hpp"
#include "my_engine.hpp"

int main(int argc, char** argv) {
  my_draw canvas;
  my_engine engine(&canvas);
  engine.run();

  return 0;
}