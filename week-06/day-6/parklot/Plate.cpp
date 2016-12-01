#include "Plate.hpp"
#include <iostream>
string letters = "QWERTYUIOPASDFGHJKLZXCVBNM";
string numbers = "0123456789";

Plate::Plate(unsigned short int id) {
  temp_plate = "   -   ";
  for (int i = 0; i < 3; i++) {
    temp_plate[i] = letters[rand() % 26];
  }
  for (int i = 0; i < 3; i++) {
    temp_plate[i + 4] = numbers[rand() % 10];
  }
}

string Plate::get_temp_plate() {
  return temp_plate;
}
