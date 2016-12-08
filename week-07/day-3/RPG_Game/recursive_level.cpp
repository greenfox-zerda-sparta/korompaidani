#include "recursive_level.hpp"

const int STEPS[15] = { 3,3,4,5,4,4,4,5,5,5,5,5,6,6,6 };
const int COVERABLE = 54;

recursive_level::recursive_level() : level_builder() {
}

recursive_level::~recursive_level() {
}

void recursive_level::drawer(int x, int y, int covered) {
  if (!map[x][y]) {
    map[x][y] = 1;
    ++covered;
  }
  if (covered >= COVERABLE) {
    return;
  }
  int stp = rand() % 15;
  int dir = rand() % 4;
  for (int i = 1; i <= STEPS[stp]; ++i) {
    if (dir == 0) { //right
      if (++x > 9) {
        x = 9;
        dir = rand() % 4;
      }
      if (!map[x][y]) {
        ++covered;
        map[x][y] = 1;
      }
    }
    else if (dir == 1) { //down
      if (++y>9) {
        y = 9;
        dir = rand() % 4;
      }
      if (!map[x][y]) {
        ++covered;
        map[x][y] = 1;
      }
    }
    else if (dir == 2) { // left
      if (--x<0) {
        x = 0;
        dir = rand() % 4;
      }
      if (!map[x][y]) {
        ++covered;
        map[x][y] = 1;
      }
    }
    else { // up
      if (--y<0) {
        y = 0;
        dir = rand() % 4;
      }
      if (!map[x][y]) {
        ++covered;
        map[x][y] = 1;
      }
    }
    if (covered == COVERABLE) {
      return;
    }
  }
  drawer(x, y, covered);
  return;
}
