#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include "ParkingLot.hpp"

class Register {
  private:
    ParkingLot* pl;
  public:
    Register(ParkingLot);
    void print_all_parking_car();
};

#endif // REGISTER_H
