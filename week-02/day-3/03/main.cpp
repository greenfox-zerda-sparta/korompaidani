#include <iostream>

using namespace std;

int main() {
  int number = 1234;
  int* number_pointer = &number; ///this is not a copy of our variable's value we only use a simple pointer to store data in the original place
  // update the value of number variable to 42 using the "number_pointer"

  *number_pointer=42;

  cout << number;

  return 0;
}
