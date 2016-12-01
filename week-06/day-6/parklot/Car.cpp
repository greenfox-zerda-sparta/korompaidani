#include "Car.hpp"

std::string car_factory[18] = {"Moszkvics", "Volga", "ZISZ", "Tatra", "Zbrojovka", "Hotchkiss", "DAF", "Warszawa", "Puli", "Balaton", "Benz", "Marauder", "Zsiguli" , "IFA", "Fjord", "Trabant", "Wartburg", "Martini"};
std::string car_paint[10] = {"Piros", "Narancssarga", "Zold", "Kek", "Turkiz", "Barna", "Lila", "Sarga", "Fekete", "Feher"};

unsigned short int Car::ID_COUNTER = 1;

Car::Car() : CAR_ID(ID_COUNTER) {
unsigned short int car_factory_index = rand() % (sizeof(car_factory) / sizeof(std::string));
unsigned short int car_paint_index = rand() % (sizeof(car_paint) / sizeof(std::string));

type = car_factory[car_factory_index];
color = car_paint[car_paint_index];
car_plate = "";
ID_COUNTER++;
}

std::string Car::get_type() {
  return type;
}

std::string Car::get_color() {
  return color;
}

std::string Car::get_car_plate() {
  return car_plate;
}

unsigned short int Car::get_CAR_ID() {
  return CAR_ID;
}
