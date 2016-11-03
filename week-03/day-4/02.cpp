#include <string>
#include <iostream>

using namespace std;

struct RectangularCuboid {
  double a;
  double b;
  double c;
};

double get_surface(RectangularCuboid rc) {
  return 2 * rc.a * rc.b + 2 * rc.b * rc.c + 2 * rc.a * rc.c;
}

// Write a function called "get_surface" that takes a RectangularCuboid
// and returns it's surface

// Write a function called "get_volume" that takes a RectangularCuboid
// and returns it's volume

int main() {
  RectangularCuboid rc1 = {3, 4, 5};

  cout <<  get_surface(rc1);


  return 0;
}
