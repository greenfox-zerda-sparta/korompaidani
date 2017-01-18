#include <iostream>
#include <string>
#include "triangle.h"

using namespace std;

void triangle::stardrawer(int in_length) {
  length = in_length;
  char star = '*';
  string stars = "*";
  for (int j = 1; j <= length; j ++){
    for (int i = 0; i < j; i ++) {
      cout << star;
  }
  cout << endl;
  }
}

void triangle::get_length() {
  cout << "\nThe length is: " << length;
};
