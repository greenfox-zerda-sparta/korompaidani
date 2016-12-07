#include "my_game.hpp"

const int steps[15] = { 3,3,4,5,4,4,4,5,5,5,5,5,6,6,6 };
const int COVERABLE = 54;

my_game::my_game() {
  this->map_size = 10;
  this->map.resize(map_size);
  for (int i = 0; i < map.size(); i++) {
    map[i].resize(map_size, 0);
  }
  this->player_path.resize(map_size);
  for (int i = 0; i < map.size(); i++) {
    player_path[i].resize(map_size, 0);
  }
  /*
  shift = -2;
  frame_size = map_size;
  square_drawer();
  square_drawer();
  square_drawer();
  */

  reqursive_drawer(0, 0, 0);
};

void my_game::square_drawer() {
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

void my_game::reqursive_drawer(int x, int y, int covered) {
  if (!map[x][y]) {
    map[x][y] = 1;
    ++covered;
  }
  if (covered >= COVERABLE) {
    return;
  }
  int stp = rand() % 15;
  int dir = rand() % 4;
  for (int i = 1; i <= steps[stp]; ++i) {
    if (dir == 0) { //right
      if (++x>9) {
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
  reqursive_drawer(x, y, covered);
  return;
};

my_game::~my_game() {
};

void my_game::init(GameContext& context) {
  context.load_file("pics/floor.bmp");
  context.load_file("pics/wall.bmp");
  context.load_file("pics/hero-down.bmp");
};

//context.draw_sprite("pics/floor.bmp", i * 72, j * 72);
//context.render();

void my_game::render(GameContext& context) {

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
 
  int x = 0;
  int y = 0;
  /*
  context.draw_sprite("pics/hero-down.bmp", x * 72, y * 72);
  if (context.was_key_pressed(ARROW_DOWN) == true) {
    y += 1;
  }
  context.reset_keys();
  context.on_key_down(ARROW_DOWN);
  context.draw_sprite("pics/hero-down.bmp", x * 72, y * 72);
  context.render();
  */
  context.draw_sprite("pics/hero-down.bmp", x, y);
  if (context.was_key_pressed(ARROW_DOWN)) {
    y = y + 72;
    if (y > (720 - 72)) {
      y = (720 - 72);
      context.render();
    }
    /*else if (map[x / 72][y / 72] % 5 == 0) {
      y = y - 72;
    }*/
    context.reset_keys();
    context.on_key_down(ARROW_DOWN);
    context.draw_sprite("pics/hero-down.bmp", x, y);
  }
  context.render();
};

/*
this->map.resize(10);
for (int i = 0; i < map.size(); i++) {
  map[i].resize(10);
}
for (int i = 0; i < map.size(); i++) {
  for (int j = 0; j < map[i].size(); j++) {
    map[i][j] = rand() % 2;
  }
}
*/