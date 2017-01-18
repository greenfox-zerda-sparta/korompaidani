#include <iostream>
#include <string>
#include "Shape.h"
#include "Triangle.h"


using namespace std;

Triangle::Triangle() {
}

string* Triangle::getName() {
  return new string("Triangle");
}
