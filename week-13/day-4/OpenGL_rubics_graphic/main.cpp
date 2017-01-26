#include "Opengl.hpp"
#include "Camera.hpp"
#include "Cube_drawer.hpp"
#include "User_input.hpp"
#include "cube.h"

#define WIDTH 1920
#define HEIGHT 1080

int main(int argc, char* argv[]) {

  Cube my_cube;

  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *screen;
  screen = SDL_CreateWindow("Rubic's  window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
  SDL_GL_CreateContext(screen);

  Opengl opgl;
  Camera cam;
  Cube_drawer primitive;

  primitive.load_texture("pics/green.bmp");
  primitive.load_texture("pics/red.bmp");
  primitive.load_texture("pics/blue.bmp");
  primitive.load_texture("pics/orange.bmp");
  primitive.load_texture("pics/white.bmp");
  primitive.load_texture("pics/yellow.bmp");

  User_input ui(WIDTH, HEIGHT);
  opgl.opengl_init(WIDTH, HEIGHT);
  
  bool running = true;
  while (running) {
    ui.input_handler(running, my_cube);
    opgl.opengl_sreenbuilder();
    cam.place_camera();
    cam.rotate_camera(ui.get_angle_x(), ui.get_angle_z());
    //primitive.draw_flattened_cube(my_cube.get_vector_for_Lego(), 3);
    primitive.draw_real_cube(my_cube.get_vector_for_Lego(), 3);

    opgl.opengl_display(screen);
  }

  SDL_Quit();
  return 0;
}