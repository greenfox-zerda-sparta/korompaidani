#include <iostream>
#include <string>
#include "Shape.h"

using namespace std;

Shape::Shape() {
}

string* Shape::getName() {
  return new string("Generic Shape");
}
