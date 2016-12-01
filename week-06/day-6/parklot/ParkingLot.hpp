#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Plate.hpp"
#include "Car.hpp"
#include <vector>

using namespace std;

class ParkingLot {
  private:
    int row;
    int col;
    int level;
    vector<vector<vector<Car*> > > parking_house;
  public:
    ParkingLot(int, int, int);
    Car* get_cars_from_parking_house(int, int, int);
};

#endif // PARKINGLOT_H
