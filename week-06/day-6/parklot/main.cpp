#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

#include "Car.hpp"
#include "Plate.hpp"

using namespace std;

int main() {
  srand(unsigned(time(0)));

  vector<Car*> garage (5);
  for (int i = 0; i < garage.size(); i++) {
    garage[i] = new Car();
    cout << i + 1 << ". garage: " << garage[i]->get_type() << " | " << garage[i]->get_color() << " | " << garage[i]->get_car_plate() << " | " << garage[i]->get_CAR_ID() << endl;
  }

  Plate p1(2);

  cout << p1.get_temp_plate() << endl;

  return 0;
}

//Create a vector of string, for the following car types:
	//Create a vector of strings, for the following colors:
	//Create a Car class, which holds 3 strings, the name of a car, the color of it, and the platenumber in a format like "AAA"-"000"
	//Create a 3 dimensional vector of our car class, that will represent a "parking house"
		//1 dimension: row of cars
		//2 dimension: cars on a platform like a table game
		//3 dimension: "parking house"
	//Make this parking house 4*4*8 (4*4 platform on 8 floors), then fill it with cars! :)
	//Give these cars a random type from our car type vector!
	//Give these cars a random color from our color vector!
	//Give these cars a random plate number!
	//Make sure there are no duplicates in car plates!
	//Print out how much "Sárga"-"Zsiguli" we have, with their position and platenumber in the parking house!
	//At the end empty the parking house!
