#include <iostream>
#include "Rock.h"

Rock::Rock(std::string intitle, std::string inartist) : Song(intitle, inartist) {
  std::cout << "Do U see me?";
}

