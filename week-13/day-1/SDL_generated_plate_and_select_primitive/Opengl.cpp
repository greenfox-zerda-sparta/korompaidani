#include "Opengl.hpp"

#define BUFSIZE 512

Opengl::Opengl() {
}

Opengl::~Opengl() {
}

void Opengl::opengl_init(int width, int height) {
  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, /*SDL_WINDOW_FULLSCREEN |*/ SDL_WINDOW_OPENGL);
  SDL_GL_CreateContext(screen);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, (double)width / height, 1, 1000);
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_FLAT);
  glDepthRange(0.0, 1.0);
}

void Opengl::opengl_sreenbuilder() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Opengl::opengl_display() {
  glFlush();
  SDL_GL_SwapWindow(screen);
}

void Opengl::pick_objects(int button, int state, int x, int y) {
  GLUuint selectBuf[BUFSIZE];
  GLint hits;
  GLint viewport[4];
  if (button != SDL_MOUSEBUTTONDOWN || state != SDL_PRESSED) {
    return;
  }
  glGetIntegerv(GL_VIEWPORT, viewport);
  glSelectBuffer(BUFSIZE, selectBuf);
  (void)glRenderMode(GL_SELECT);

  glInitNames();
  glPushName(0);

  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluPickMatrix((GLdouble)x, (GLdouble)(viewport[3] - y), 5.0, 5.0, viewport);
  glOrtho(0.0, 8.0, 0.0, 8.0, -0.5, 2.5);
  quad_map.generate_tile_net(repeat, mode);
  glPopMatrix();
  glFlush();

  hits = glRenderMode(GL_RENDER);
  ///std::cout << selectBuf[hits] << std::endl;
}

void Opengl::display_objects(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  quad_map.generate_tile_net(repeat, mode);
}

