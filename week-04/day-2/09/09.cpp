#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

int main() {
    // Create a student Class
    // that has a method `add_grade`, that takes a grade from 1 to 5
    // an other method `get_average`, that returns the average of the
    // grades
  Student carl;
  carl.add_grade(5);
  carl.add_grade(4);
  cout << carl.get_average();

  return 0;
}
