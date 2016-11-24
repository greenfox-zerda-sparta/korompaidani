#include <iostream>
#include <string>

using namespace std;

template <class dani>
dani first_element_of_array(dani* array, int size) {
  return array[size];
}

int main() {

  int arr_int[3] = {7, 8, 4};
  float arr_float[3] = {7.6, 3.8, 2.4464};
  char arr_char[3] = {'d', 'a', 'n'};
  string arr_string[3] = {"oh", "yeah", "huh"};

  cout << first_element_of_array(arr_int, 0) << endl;
  cout << first_element_of_array(arr_float, 0) << endl;
  cout << first_element_of_array(arr_char, 0) << endl;
  cout << first_element_of_array(arr_string, 0) << endl;
	// create a function template the takes in a fix long array and prints the 1st element of it

  return 0;
}
