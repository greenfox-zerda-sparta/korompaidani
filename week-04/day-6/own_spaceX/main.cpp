#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Tool {
public:
  string to_string(int number);
};

string to_string(int number) {
  stringstream ss;
  ss << number;
  return ss.str();
};

class Rocket {
protected:
  int fuel_consumption;
  int tank_size;
  string type_name;
private:
  int number_of_launches;
  int fuel_level;
public:
  Rocket();
  void launch();
  int refill();
  string get_stats();
};

Rocket::Rocket() {
  this->number_of_launches = 0;
  this->fuel_level = 0;
};

void Rocket::launch() {
  ++number_of_launches;
  fuel_level -= fuel_consumption;
};

int Rocket::refill() {
  int actual_refill_quant = tank_size - fuel_level;
  fuel_level = tank_size;
  return actual_refill_quant;
};

string Rocket::get_stats() {
  return type_name + ", fuel: " + to_string(fuel_level) + ", launches: " + to_string(number_of_launches) + "\n";
};

class Falcon1 : public Rocket {
public:
  Falcon1();
};

Falcon1::Falcon1() {
  fuel_consumption = 1;
  tank_size = 3;
  type_name = "Falcon_1";
};

class Falcon9 : public Rocket {
public:
  Falcon9();
};

Falcon9::Falcon9() {
  fuel_consumption = 9;
  tank_size = 20;
  type_name = "Falcon_9";
};

class SpaceX {
private:
  int fuel_base;
  Rocket** rocket;
  int rocket_counter;
public:
  SpaceX(int fuel_input);
  void add_rocket(Rocket& rocket);
};

SpaceX::SpaceX(int fuel_input) {
  fuel_base = fuel_input;
  rocket = NULL;
  rocket_counter = 0;
};

void SpaceX::add_rocket(Rocket& in_rocket) {
  Rocket** temp = new Rocket*[rocket_counter + 1];
  for (int i = 0; i < rocket_counter; i++) {
    temp[i] = rocket[i];
  }
  temp[rocket_counter] =  &in_rocket;
  delete[] rocket;
  rocket = temp;
  ++rocket_counter;
};

int main()
{
  Falcon1 r1;
  Falcon9 r2;

  cout << r1.get_stats();
  cout << r2.get_stats();

  r1.refill();
  r2.refill();
  r1.launch();
  r2.launch();

  r1.launch();
  r2.launch();
  r1.refill();
  r2.refill();

  cout << r1.get_stats();
  cout << r2.get_stats();

  return 0;
}
