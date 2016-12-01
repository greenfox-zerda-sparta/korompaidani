#ifndef PLATE_H
#define PLATE_H

#include "Car.hpp"
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

class Plate : Car {
  private:
    std::string temp_plate;
  public:
    Plate(unsigned short int);
    std::string get_temp_plate();
};

#endif // PLATE_H
