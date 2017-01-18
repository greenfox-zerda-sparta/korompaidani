#include "my_game.hpp"

my_game::my_game(std::string player_1_name, std::string player_2_name, unsigned short int screen_size, unsigned short int map_size, Client_cl& cli, Server_sr& srv) {
  this->my_map = new Map(map_size);
  this->player_1 = new Player(player_1_name);
  this->player_2 = new Player(player_2_name, *player_1);
  this->scan = new Scan;
  this->sdl_window = new SDL_Window(screen_size, screen_size, screen_size / map_size);
  this->player_1_name = player_1_name;
  this->player_2_name = player_2_name;
  this->screen_size = screen_size;
  this->map_size = map_size;
  this->my_client = cli;
  this->my_server = srv;
}

my_game::~my_game() {
  delete my_map;
  delete player_1;
  delete player_2;
  delete scan;
  delete sdl_window;
}

void my_game::game_handler() {
}

void my_game::launch() {
  if (player_1_name != "Default") {
    my_server.server_init();
    std::cout << "there was server init" << std::endl;
    sdl_window->run_as_server(*my_map, *player_1, *player_2, *scan, my_client, my_server);
  }
  else {
    //my_client.client_run();
    my_client.client_init();
    std::cout << "there was client init" << std::endl;
    sdl_window->run_as_client(*my_map, *player_1, *player_2, *scan, my_client, my_server);
  }
  
  sdl_window->create_win_window();
}

void my_game::print_map_vector() {
  for (int i = 0; i < my_map->get_map().size(); i++) {
    for (int j = 0; j < my_map->get_map()[i].size(); j++) {
      std::cout << my_map->get_map()[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}