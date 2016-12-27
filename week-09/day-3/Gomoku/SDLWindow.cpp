#include "SDLWindow.hpp"

SDL_Window::SDL_Window(int width, int height, int tile_size) {
  this->width = width;
  this->height = height;
  this->tile_size = tile_size;
  this->map_size = width / tile_size;
  this->o_image = "o.bmp";
  this->x_image = "x.bmp";
  this->board_image = "board.bmp";
}

void SDL_Window::create_window() {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Gomoku", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
  //draw_full_size_image(1);
  drawbackground();
}

void SDL_Window::run(Map& map, Player& player_1, Player& player_2) {
  bool temp;
  create_window();
  fill_image_by_tile(map_size);
  int player_switcher = 1;
  bool running = true;
  while (running) {    
    if (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        running = false;
        break;
      }
    }
    if (player_switcher == 1) {
      temp = game_logic(map, player_1);
      if (temp == true) {
        player_switcher = 2;
        std::cout << "player_switcher= " << player_switcher << std::endl;
      }
    }
    else if (player_switcher == 2) {
      temp = game_logic(map, player_2);
      if (temp == true) {
        player_switcher = 1;
        std::cout << "player_switcher= " << player_switcher << std::endl;
      }
    }
  }
}

bool SDL_Window::game_logic(Map& map, Player& player_1) {
  if (event.type == SDL_MOUSEBUTTONDOWN) {
    if (map.set_map_value_by_coordinates(event.button.x / tile_size, event.button.y / tile_size, player_1.get_player_num()) != ERR_CODE_8) {
      click_coordinates.first = event.button.x / tile_size;
      click_coordinates.second = event.button.y / tile_size;
      cout << "x= " << get_click_coordinates().first << " y= " << get_click_coordinates().second << endl;
      drawimage(event.button.x, event.button.y, player_1.get_player_num());
      event.type = NULL;
      return true;
    }
    else {
      cout << "fail" << endl;
      event.type = NULL;
      return false;
    }
  }
}

pair <int, int> SDL_Window::get_click_coordinates() {
  return click_coordinates;
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
  image = SDL_LoadBMP(board_image);
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