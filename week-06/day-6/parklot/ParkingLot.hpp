#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Plate.hpp"
#include "Car.hpp"
#include <vector>

using namespace std;

class ParkingLot {
  private:
    string parking_name;
    int row;
    int col;
    int level;
    vector<vector<vector<Car*> > > parking_house;
  public:
    int get_row();
    int get_col();
    int get_level();
    string get_parking_name();
    ParkingLot(int, int, int, string);
    Car* get_cars_from_parking_house(int, int, int);
};

#endif // PARKINGLOT_H
