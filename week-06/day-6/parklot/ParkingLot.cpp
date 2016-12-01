#include "ParkingLot.hpp"

ParkingLot::ParkingLot(int user_row, int user_col, int user_level) {
  this->row = user_row;
  this->col = user_col;
  this->level = user_level;

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
        Plate pt(parking_house[i][j][k]->get_CAR_ID());
        parking_house[i][j][k]->set_car_plate(pt.get_temp_plate());
      }
    }
  }
}

Car* ParkingLot::get_cars_from_parking_house(int user_row, int user_col, int user_level) {
  return parking_house[user_row][user_col][user_level];
}
