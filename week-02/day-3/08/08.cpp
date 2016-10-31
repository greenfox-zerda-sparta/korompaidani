#include <iostream>

using namespace std;

void swap(int)

int main() {
  int high_number = 2;
  int low_number = 6655;

  int* hight_number_pointer = &high_number;
  int* low_number_pointer = &low_number;
  // Please fix the problem and swap the value of the variables,
  // without using the "high_number" and the "low_number" variables.

  int buffer_variable= *hight_number_pointer;
  *hight_number_pointer = *low_number_pointer;
  *low_number_pointer = buffer_variable;

  cout << high_number << endl;
  cout << low_number << endl;

  return 0;
}
