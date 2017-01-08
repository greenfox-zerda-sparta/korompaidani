#include "SDLWindow.hpp"
#include "Tools.hpp"

SDL_Window::SDL_Window(int width, int height, int tile_size) {
  this->width = width;
  this->height = height;
  this->tile_size = tile_size;
  this->map_size = width / tile_size;
  this->o_image = "pics/o.bmp";
  this->x_image = "pics/x.bmp";
  this->board_image = "pics/board.bmp";
  this->x_win_image = "pics/x_win.bmp";
}

void SDL_Window::create_window() {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Gomoku", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
  //draw_full_size_image(1);
  drawbackground();
}

void SDL_Window::create_win_window() {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("win", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_OPENGL);
  bool running = true;
  while (running) {
    if (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        running = false;
        return;
      }
    }
    draw_full_size_image(1);
  }
}

void SDL_Window::run_as_client(Map& map, Player& player_1, Player& player_2, Scan& scan, Client_cl& my_client, Server_sr& my_server) {
  bool temp;
  create_window();
  fill_image_by_tile(map_size);
  int player_switcher = 1;
  bool running = true;
  while (running) {    
    if (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        running = false;
        return;
      }
    }
    if (player_switcher == 1) {
      temp = enemy_at_client(map, scan, running, my_client);
      if (temp == true) {
        player_switcher = 2;
        std::cout << "player_switcher= " << player_switcher << std::endl;
      }
    }
    else if (player_switcher == 2) {
      temp = game_logic_at_client(map, player_1, scan, running, my_client);
      if (temp == true) {
        player_switcher = 1;
        std::cout << "player_switcher= " << player_switcher << std::endl;
      }
    }
  }
  my_client.client_close();
}

void SDL_Window::run_as_server(Map& map, Player& player_1, Player& player_2, Scan& scan, Client_cl& my_client, Server_sr& my_server) {
  bool temp;
  create_window();
  fill_image_by_tile(map_size);
  int player_switcher = 1;
  bool running = true;
  while (running) {
    if (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        running = false;
        return;
      }
    }
    if (player_switcher == 1) {
      temp = game_logic_at_server(map, player_1, scan, running, my_server);
      if (temp == true) {
        player_switcher = 2;
        std::cout << "player_switcher= " << player_switcher << std::endl;
      }
    }
    else if (player_switcher == 2) {
      
      temp = enemy_at_server(map, scan, running, my_server);
      if (temp == true) {
        player_switcher = 1;
        std::cout << "player_switcher= " << player_switcher << std::endl;
      }
    }
  }
  my_client.client_close();
}

bool SDL_Window::game_logic_at_client(Map& map, Player& player, Scan& scan, bool& running, Client_cl& my_client) {
  std::string temp;
  if (event.type == SDL_MOUSEBUTTONDOWN) {
    player.set_last_click_coordinates(event.button.x / tile_size, event.button.y / tile_size);
    if (player.choise(map, event.button.x / tile_size, event.button.y / tile_size)) {
      player.choise(map, event.button.x / tile_size, event.button.y / tile_size);
      drawimage(event.button.x, event.button.y, player.get_player_num());
      
      temp = m_int_to_string(player.get_last_click_coordinates().first) + "," + m_int_to_string(player.get_last_click_coordinates().second) + "\n";
      my_client.client_send(temp); ///
      std::cout << "the sent client message was: " << temp << std::endl;
     
      scan.round_scan(map, player.get_last_click_coordinates(), player.get_player_num());
      if (scan.get_win_player_num() == player.get_player_num()) {
        scan.reset_win_player_num();
        map.reset_map();
        fill_image_by_tile(map_size);
        running = false;        
        event.type = NULL;
      }
      event.type = NULL;
      return true;
    }
    else {
      event.type = NULL;
      return false;
    }
  }
}

bool SDL_Window::game_logic_at_server(Map& map, Player& player, Scan& scan, bool& running, Server_sr& my_server) {
  std::string temp;
  if (event.type == SDL_MOUSEBUTTONDOWN) {
    player.set_last_click_coordinates(event.button.x / tile_size, event.button.y / tile_size);
    if (player.choise(map, event.button.x / tile_size, event.button.y / tile_size)) {
      player.choise(map, event.button.x / tile_size, event.button.y / tile_size);
      drawimage(event.button.x, event.button.y, player.get_player_num());
      temp = m_int_to_string(player.get_last_click_coordinates().first) + "," + m_int_to_string(player.get_last_click_coordinates().second) + "\n";
      my_server.server_send(temp); ///
      std::cout << "the sent server message was: " << temp << std::endl;
      scan.round_scan(map, player.get_last_click_coordinates(), player.get_player_num());
      if (scan.get_win_player_num() == player.get_player_num()) {
        scan.reset_win_player_num();
        map.reset_map();
        fill_image_by_tile(map_size);
        running = false;
        event.type = NULL;
      }
      event.type = NULL;
      return true;
    }
    else {
      event.type = NULL;
      return false;
    }
  }
}

bool SDL_Window::enemy_at_client(Map& map, Scan& scan, bool& running, Client_cl& my_client) {
  int x, y;
  ///while (1) {
      std::pair<int, int> tempair = m_string_to_int_pair(my_client.client_receive()); ///
      x = tempair.first * tile_size;
      y = tempair.second * tile_size;
      std::cout << "x= " << x / tile_size << std::endl;
      std::cout << "y= " << y / tile_size << std::endl;
      map.set_map_value_by_coordinates(tempair.first, tempair.second, 2);
      drawimage(x, y, 2);
      ///break;
  ///}
  return true;
}

bool SDL_Window::enemy_at_server(Map& map, Scan& scan, bool& running, Server_sr& my_server) {
  int x, y;
  ///while (1) {
    std::pair<int, int> tempair = m_string_to_int_pair(my_server.server_receive()); ///
    x = tempair.first * tile_size;
    y = tempair.second * tile_size;
    std::cout << "x= " << x / tile_size << std::endl;
    std::cout << "y= " << y / tile_size << std::endl;
    map.set_map_value_by_coordinates(tempair.first, tempair.second, 2);
    drawimage(x, y, 2);
    ///break;
  ///}
  return true;
}

void SDL_Window::drawbackground() {
  renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_Rect dstrect = { tile_size, tile_size, tile_size, tile_size };
  SDL_SetRenderDrawColor(renderer, 239, 228, 176, 255);
  texture = SDL_CreateTextureFromSurface(renderer, image);
  SDL_RenderCopy(renderer, texture, NULL, &dstrect);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

void SDL_Window::drawimage(int& x, int& y, int player_num) {
  if (player_num == 1) {
    image = SDL_LoadBMP(o_image);
  }
  else if (player_num == 2) {
    image = SDL_LoadBMP(x_image);
  }
  SDL_Rect dstrect = { (x / tile_size) * tile_size, (y / tile_size) * tile_size, tile_size, tile_size };
  texture = SDL_CreateTextureFromSurface(renderer, image);
  SDL_RenderCopy(renderer, texture, NULL, &dstrect);
  SDL_RenderPresent(renderer);
  SDL_RenderPresent(renderer);  
}

void SDL_Window::fill_image_by_tile(int map_size) {
  image = SDL_LoadBMP(board_image);
  for (int i = 0; i < map_size; i++) {
    for (int j = 0; j < map_size; j++) {
      SDL_Rect dstrect = { (i) * tile_size, (j) * tile_size, tile_size, tile_size };
      texture = SDL_CreateTextureFromSurface(renderer, image);
      SDL_RenderCopy(renderer, texture, NULL, &dstrect);
      SDL_RenderPresent(renderer);
      SDL_RenderPresent(renderer);
    }
  }
}

void SDL_Window::draw_full_size_image(int image_size) {
  renderer = SDL_CreateRenderer(window, -1, 0);
  image = SDL_LoadBMP(x_win_image);
  texture = SDL_CreateTextureFromSurface(renderer, image);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
}

SDL_Window::~SDL_Window() {
  SDL_FreeSurface(image);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyTexture(texture);
  SDL_DestroyWindow(window);
  SDL_Quit();
}