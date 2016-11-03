#include <string>
#include <iostream>

using namespace std;

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
  CarType type;
  double km;
  double gas;
};

Car* get_car() {
  Car* carray = new Car[10];
  int counter = 0;
  for(int i = 0; i < 10; i++) {
    if(counter == 3) {
      carray[i].type = (CarType)counter;
      counter = 0;
    }
    else {
      carray[i].type = (CarType)counter;
      counter ++;
    }
  }
  for(int i = 0; i < 10; i++) {
    if(carray[i].type  < 4) {
      carray[i].km = 400;
      carray[i].gas = 50;
    }
    else {
      carray[i].km = 400;
      carray[i].gas = 0;
    }
  }
  return carray;
}

void print_car(Car* s) {
  for(int i = 0; i < 10; i++) {
    if(s[i].type == TESLA) {
      cout << "Car type: " << s[i].type << "\tkm: " << s[i].km << endl;
    }
    else {
      cout << "Car type: " << s[i].type << "\tkm: " << s[i].km << "\t\tgas: " << s[i].gas << endl;
    }
  }
}


// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

int main() {
  Car* carray = get_car();
  print_car(carray);
  delete[] carray;
  return 0;
}
