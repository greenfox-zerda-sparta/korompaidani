#include <iostream>
#include <string>
#ifndef PIRATE_H
#define PIRATE_H


class pirate
{
  public:
    void drink_rum();
    void hows_goin_mate();
  private:
    int rum = 1;
};

#endif // PIRATE_H

    // create a pirate class
    // it should have 2 methods
    // drink_rum()
    // hows_goin_mate()
    // if the drink_rum was called at least 5 times:
    // hows_goin_mate should return "Arrrr!"
    // "Nothin'" otherwise
