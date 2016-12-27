#include "my_game.hpp"

Map my_map(19);
Player player_1("a");
Player player_2("b", player_1);
SDL_Window sdl_window(570, 570, 30);

my_game::my_game(std::string player_1_name, std::string player_2_name, unsigned short int screen_size, unsigned short int map_size) {
  this->player_1_name = player_1_name;
  this->player_2_name = player_2_name;
  this->screen_size = screen_size;
  this->map_size = map_size;
}

void my_game::game_handler() {
  sdl_window.game_logic(my_map, player_2);
}

void my_game::launch() {
  sdl_window.run(my_map, player_2);
  print_map_vector();
}

void my_game::print_map_vector() {
  for (int i = 0; i < my_map.get_map().size(); i++) {
    for (int j = 0; j < my_map.get_map()[i].size(); j++) {
      std::cout << my_map.get_map()[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}