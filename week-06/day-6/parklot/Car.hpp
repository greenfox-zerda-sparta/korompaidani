#ifndef CAR_H
#define CAR_H

#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

class Car {
  private:
    static unsigned short int ID_COUNTER;
    const unsigned short int CAR_ID;
    std::string type;
    std::string color;
    std::string car_plate;
  public:
    Car();
    void set_car_plate(std::string);
    std::string get_type();
    std::string get_color();
    std::string get_car_plate();
    unsigned short int get_CAR_ID();
};

#endif // CAR_H
