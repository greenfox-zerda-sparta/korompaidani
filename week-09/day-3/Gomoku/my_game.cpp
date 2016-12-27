#include "my_game.hpp"

my_game::my_game(std::string player_1_name, std::string player_2_name, unsigned short int screen_size, unsigned short int map_size) {
  this->my_map = new Map(map_size);
  this->player_1 = new Player(player_1_name);
  this->player_2 = new Player(player_2_name, *player_1);
  this->sdl_window = new SDL_Window(screen_size, screen_size, screen_size / map_size);
  this->player_1_name = player_1_name;
  this->player_2_name = player_2_name;
  this->screen_size = screen_size;
  this->map_size = map_size;
}

my_game::~my_game() {
  delete my_map;
  delete player_1;
  delete player_2;
  delete sdl_window;
}

void my_game::game_handler() {
  sdl_window->game_logic(*my_map, *player_1);
}

void my_game::launch() {
  sdl_window->run(*my_map, *player_1);
  print_map_vector();
}

void my_game::print_map_vector() {
  for (int i = 0; i < my_map->get_map().size(); i++) {
    for (int j = 0; j < my_map->get_map()[i].size(); j++) {
      std::cout << my_map->get_map()[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}