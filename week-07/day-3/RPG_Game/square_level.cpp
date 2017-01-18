#include "square_level.hpp"

square_level::square_level() : level_builder() {
  shift = -2;
  frame_size = map_size;
  square_drawer();
  square_drawer();
  square_drawer();
}

square_level::~square_level() {
}

void square_level::square_drawer() {
  if (frame_size >= map_size) {
    frame_size = map_size;
  }
  shift += 2;
  int max_size = frame_size - shift;
  int min_size = shift;
  int rand_int = (rand() % (max_size - shift));

  for (int i = min_size; i < max_size; i++) {
    for (int j = min_size; j < max_size; j++) {
      if (i == min_size || i == max_size - 1) {
        map[i][j] = 1;
      }
      else {
        if (j == min_size || j == max_size - 1) {
          map[i][j] = 1;
        }
      }
    }
  }
}
