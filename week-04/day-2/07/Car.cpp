#include <iostream>
#include <string>
#include "Car.h"


Car::Car(std::string in_type, double in_km) {
  this->type = in_type;
  this->km = in_km;
};
void Car::run(double run) {
  this->km = this->km + run;
};
double Car::get_km() {
  return this->km;
}

