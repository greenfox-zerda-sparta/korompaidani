#include <iostream>
#include <string>
#include "pirate.h"

void pirate::drink_rum() {
  this->rum += 1;
};
void pirate::hows_goin_mate() {
  if (this->rum > 5) {
    std::cout << "Arrrr!";
  }
  else {
    std::cout << "Nothing!";
  }
};

