#include <SDL.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using std::cerr;
using std::endl;

const int WINDOW_HEIGHT = 640;
const int WINDOW_WIDTH = 480;
/*
void level_creator() {
  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map[i].size(); j++) {
      if (map[i][j] == 1) {
        context.draw_sprite(floor_pic_path, i * 72, j * 72);
      }
      else {
        draw_sprite(wall_pic_path, i * 72, j * 72);
      }
    }
  }
}
*/
int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window;
  //SDL_Surface* pureSurface;
  std::map<std::string, SDL_Texture*> pictures;
  SDL_Renderer* renderer;
  SDL_Event event;

  window = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);

  std::string pic1 = "floor.bmp";
  std::string pic2 = "wall.bmp";
  
  SDL_Surface* result = SDL_LoadBMP(pic1.c_str());
  SDL_SetColorKey(result, SDL_TRUE, SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(window)), 0xFF, 0, 0xFF));
  pictures[pic1] = SDL_CreateTextureFromSurface(renderer, result);
  SDL_FreeSurface(result);
  
  SDL_Surface* result2 = SDL_LoadBMP(pic2.c_str());
  SDL_SetColorKey(result2, SDL_TRUE, SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(window)), 0xFF, 0, 0xFF));
  pictures[pic2] = SDL_CreateTextureFromSurface(renderer, result2);
  SDL_FreeSurface(result2);

  SDL_Rect temp;
  SDL_Rect temp2;

  std::vector<std::vector<int>> my_map;
  my_map.resize(10);
  for (int i = 0; i < my_map.size(); i++) {
    my_map[i].resize(10, 0);
  }

  my_map[8][7] = 1;
  ///my_map[8][8] = 0;

  for (int i = 0; i < my_map.size(); i++) {
    for (int j = 0; j < my_map[i].size(); j++) {
      std::cout << my_map[i][j] << ' ';
    }
    std::cout << endl;
  }


  for (int i = 0; i < my_map.size(); i++) {
    for (int j = 0; j < my_map[i].size(); j++) {
      if (my_map[i][j] == 0) {

        temp.x = i * 32;
        temp.y = j * 32;
        temp.w = 32;
        temp.h = 32;
        SDL_RenderCopy(renderer, pictures[pic1], NULL, &temp);
        SDL_RenderPresent(renderer);
      }
      else if (my_map[i][j] == 1) {
        
        temp2.x = i * 32;
        temp2.y = j * 32;
        temp2.w = 32;
        temp2.h = 32;
        SDL_RenderCopy(renderer, pictures[pic2], NULL, &temp2);
        SDL_RenderPresent(renderer);
      }
    }
  }
 
  bool running = true;
  while (running) {
    if (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        running = false;
        break;
      }
    }

  }

  SDL_DestroyTexture(pictures[pic1]);
  SDL_DestroyTexture(pictures[pic2]);
  SDL_DestroyWindow(window);
  
  SDL_QUIT;

  return 0;
}