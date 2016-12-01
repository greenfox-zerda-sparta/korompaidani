#ifndef PLATE_H
#define PLATE_H

#include "Car.hpp"
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Plate : Car {
  private:
    string temp_plate;
  public:
    Plate(unsigned short int id);
    string get_temp_plate();
};

#endif // PLATE_H
