#include "my_game.hpp"

my_game::my_game() {
  std::vector<std::vector<int>> vic(10, std::vector<int>(10, 100));
  this->map = vic;
  int random_number = 0;
  for (int j = 0; j < map.size(); j++) {
    for (int i = 0; i < map[j].size(); i++) {
      random_number = rand() % 100 + 1;
      map[j][i] = random_number;
    }
  }
};

my_game::~my_game() {
};

void my_game::init(GameContext& context) {
  context.load_file("pics/floor.bmp");
  context.load_file("pics/wall.bmp");
};

void my_game::render(GameContext& context) {
  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map[i].size(); j++) {
      if (map[i][j] % 2 == 0) {
        context.draw_sprite("pics/floor.bmp", i * 72, j * 72);
      }
      else {
        context.draw_sprite("pics/wall.bmp", i * 72, j * 72);
      }
    }
  }
  context.render();
};
