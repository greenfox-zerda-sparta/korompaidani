#include <iostream>
#include <string>

using namespace std;

class Circle {
  private:
    double radius;
    const double pi = 3.14;
  public:
    Circle(double in_radius) {
      this->radius = in_radius;
    }
    double get_circumfence() {
      return 2 * this->radius * this->pi;
    }
    double get_area() {
      return this->radius * this->radius * this->pi;
    }
};

int main() {
  // Create a `Circle` class that takes it's radius as cinstructor parameter
  // It should have a `get_circumference` method that returns it's circumference
  // It should have a `get_area` method that returns it's area

  Circle c1(4);
  cout << "Circumfence: " << c1.get_circumfence() << endl;
  cout << "Area: " << c1.get_area() << endl;

  return 0;
}
