#include <iostream>

using namespace std;

int main() {
  int high_number = 2;
  int low_number = 6655;

  int* hight_number_pointer = &high_number;
  int* low_number_pointer = &low_number;
  int temp_value=*low_number_pointer;
  // Please fix the problem and swap the value of the variables,
  // without using the "high_number" and the "low_number" variables.
  *low_number_pointer=*hight_number_pointer;
  *hight_number_pointer=temp_value;
  cout <<"The value of high number is : "<<high_number << endl;
  cout <<"The value of low number is : "<<low_number << endl;
  return 0;
}
