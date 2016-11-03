#include <string>
#include <iostream>

using namespace std;

struct House {
  string address;
  int price;
  int rooms;
  float area;
};

// Create a struct that represents a House
// It should store:
//  - The address of the house
//  - The price in EUR
//  - The number of rooms
//  - The area of the house in square meters
//
// The market price of the houses is 400 EUR / square meters
// Create a function that takes a refrence to a house and decides if it's worth to buy
bool* good_price(House* h, int length, int market_price) {
  bool* temp_house = new bool[length];
  for(int i = 0; i < length; i++) {
    h[i].price < market_price ? temp_house[i] = true : temp_house[i] = false;
  }
  return temp_house;
  delete[] temp_house;
}
// (if the price is lower than the calculated price from it's area)
//
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.
//
// Create a function that takes an array of houses (and it's length),
// then it creates a new array that consists new houses with the calculated price,
// but all the other properties are the same.

int main() {

  House BudapestHouses[] = {
    {"Karoly korut 22", 450, 3, 60.3},
    {"Petofi utca 34", 390, 2, 40.6},
    {"Kossuth 5", 1200, 2, 50.4},
    {"Berzsenyi 12", 110, 1, 12.1},
  };
  const int market_price = 400;

  bool* worth_to_buy = good_price(BudapestHouses, 4, 400);
  for (int i = 0; i < 4; i++) {
    cout << worth_to_buy[i] << endl;
  }
  return 0;
}
