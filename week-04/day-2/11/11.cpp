#include <iostream>
#include <string>
#include "triangle.h"

using namespace std;

int main() {
  triangle t1;
  t1.stardrawer(5);
  t1.get_length();
    // Create a triangle class that takes a length parameter and prints a triangle like this:
    //   *
    //   **
    //   ***
    //   ****
    //   *****
    //   ******
    // It should take a number as parameter that describes how many lines the triangle has

  return 0;
}
