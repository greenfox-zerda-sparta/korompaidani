#include "SDLWindow.hpp"
#include <iostream>
#include "ERROR_CODES.hpp"

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

void SDL_Window::run(Map& map, Player& player) {
  create_window();
  fill_image_by_tile(map_size);
  bool running = true;
  while (running) {    
    if (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        running = false;
        break;
      }
    }
    game_logic(map, player);
  }
}

void SDL_Window::game_logic(Map& map, Player& player) {
  if (event.type == SDL_MOUSEBUTTONDOWN) {
    if (map.set_map_value_by_coordinates(event.button.x / tile_size, event.button.y / tile_size, player.get_player_num()) != ERR_CODE_8) {
      cout << "x= " << (event.button.x / tile_size) << " y= " << (event.button.y / tile_size) << endl;
      drawimage(event.button.x, event.button.y, player.get_player_num());
      event.type = NULL;
    }
    else {
      cout << "fail" << endl;
    }
  }
}

pair <int, int> SDL_Window::click_coordinates(int x, int y) {
  pair <int, int> coordinates;
  coordinates.first = x;
  coordinates.second = y;
  return coordinates;
}

void SDL_Window::drawbackground() {
  renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_Rect dstrect = { tile_size, tile_size, tile_size, tile_size };
  SDL_SetRenderDrawColor(renderer, 0, 100, 200, 255);
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