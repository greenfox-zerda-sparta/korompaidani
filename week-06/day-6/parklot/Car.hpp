#ifndef CAR_H
#define CAR_H

#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Car {
  private:
    static unsigned short int ID_COUNTER;
    const unsigned short int CAR_ID;
    string type;
    string color;
    string car_plate;
  public:
    Car();
    void set_car_plate(string);
    string get_type();
    string get_color();
    string get_car_plate();
    unsigned short int get_CAR_ID();
};

#endif // CAR_H
