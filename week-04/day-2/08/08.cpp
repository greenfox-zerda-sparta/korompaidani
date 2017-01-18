#include <iostream>
#include <string>
#include "pirate.h"

using namespace std;

int main() {
    // create a pirate class
    // it should have 2 methods
    // drink_rum()
    // hows_goin_mate()
    // if the drink_rum was called at least 5 times:
    // hows_goin_mate should return "Arrrr!"
    // "Nothin'" otherwise
  pirate Jack;
  Jack.drink_rum();
  Jack.hows_goin_mate();
  Jack.drink_rum();
  Jack.drink_rum();
  Jack.drink_rum();
  Jack.drink_rum();
  Jack.hows_goin_mate();

  return 0;
}
