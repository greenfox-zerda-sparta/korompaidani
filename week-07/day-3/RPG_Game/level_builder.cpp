#include "level_builder.hpp"

const int STEPS[15] = { 3,3,4,5,4,4,4,5,5,5,5,5,6,6,6 };
const int COVERABLE = 54;

level_builder::level_builder() {
  this->map_size = 10;
  this->map.resize(map_size);
  for (int i = 0; i < map.size(); i++) {
    map[i].resize(map_size, 0);
  }
  /*
  shift = -2;
  frame_size = map_size;
  square_drawer();
  square_drawer();
  square_drawer();
  */
}


level_builder::~level_builder() {
}

void level_builder::square_drawer() {
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

void level_builder::level_creator(GameContext &context) {
  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map[i].size(); j++) {
      if (map[i][j] == 1) {
        context.draw_sprite("pics/floor.bmp", i * 72, j * 72);
      }
      else {
        context.draw_sprite("pics/wall.bmp", i * 72, j * 72);
      }
    }
  }
}
