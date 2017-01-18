#include <iostream>
#include <string>

using namespace std;

class House {
  private:
    string address;
    unsigned int area;
    const unsigned int price = 400;
  public:
    House(string in_address, unsigned int in_area) {
      this->address = in_address;
      this->area = in_area;
    };
    unsigned int get_price() {
      return this->price * area;
    }
    void GetName() {
      cout << this->address << " -- " << this->area << endl;
    }
};

int main() {
  // The market price of the houses is 400 EUR / square meters
  // Create a constructor for the House class that takes it's address and area.
  House house = House("Andrassy 66", 349);
  house.GetName();
  cout << house.get_price();

  return 0;
}
