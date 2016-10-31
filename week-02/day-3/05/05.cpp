#include <iostream>

using namespace std;

int main() {
  int numbers[] = {5, 6, 7, 8, 9};
  int* number_pointer = &numbers[0];
  // The "number_pointer" should point to the third element of the array called "numbers",



  number_pointer = &numbers[2];
  cout << "int numbers 3rd element with '&' operator: " << *number_pointer << endl;

  number_pointer = &numbers[0];
// than please print its value with it. Solve the problem without reusiong the "&" operator

  *number_pointer++;
  cout << "int numbers 3rd element without '&' operator: " << ++*number_pointer << endl;

  // for geting the address of the third element.
  cout << "the adress of 3rd: " << number_pointer << endl;

  // it is my custom task:
  cout << "the adress of 3rd: " << ++number_pointer << endl;
  cout << "the adress of 3rd: " << --number_pointer << endl;

  return 0;
}
