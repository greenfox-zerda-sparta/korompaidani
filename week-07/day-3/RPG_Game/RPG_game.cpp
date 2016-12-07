#include "game-engine-2.hpp"
#include "my_game.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char* args[]) {
  my_game game;
  GameEngine engine(&game, 640, 480);
  engine.run();
  
  return 0;
}