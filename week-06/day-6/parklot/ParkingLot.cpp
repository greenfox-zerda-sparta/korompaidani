#include "ParkingLot.hpp"

ParkingLot::ParkingLot(int user_row, int user_col, int user_level, string user_parking_name) {
  this->row = user_row;
  this->col = user_col;
  this->level = user_level;
  this->parking_name = user_parking_name;

  parking_house.resize(level);
  for(int i = 0; i < level; i++) {
    parking_house[i].resize(col);
    for(int j = 0; j < col; j++) {
      parking_house[i][j].resize(row);
    }
  }

  for (int i = 0; i < parking_house.size(); i++) {
    for (int j = 0; j < parking_house[i].size(); j++) {
      for (int k = 0; k < parking_house[i][j].size(); k++) {
        parking_house[i][j][k] = new Car();
        Plate pt;
        parking_house[i][j][k]->set_car_plate(pt.get_temp_plate());
      }
    }
  }
}

Car* ParkingLot::get_cars_from_parking_house(int user_row, int user_col, int user_level) {
  return parking_house[user_row][user_col][user_level];
}

int ParkingLot::get_row() {
  return row;
}

int ParkingLot::get_col() {
  return col;
}

int ParkingLot::get_level() {
  return level;
}

string ParkingLot::get_parking_name() {
  return parking_name;
}
