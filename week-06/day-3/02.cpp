#include <iostream>
#include <string>

using namespace std;

template <class dani>
dani add_first_element_to_third(dani* array, int size) {
  return array[2] += array[0];
}

int main() {

  int arr_int[3] = {7, 8, 4};
  float arr_float[3] = {7.6, 3.8, 2.4464};
  char arr_char[3] = {'d', 'a', 'n'};
  string arr_string[3] = {"oh", "yeah", "huh"};

  add_first_element_to_third(arr_int, 0);
  add_first_element_to_third(arr_float, 0);
  add_first_element_to_third(arr_char, 0);
  add_first_element_to_third(arr_string, 0);

  cout << arr_int[2] << endl;
  cout << arr_float[2] << endl;
  cout << arr_char[2] << endl;
  cout << arr_string[2] << endl;

	// create a function template that takes fix long array
	// and add the 1st element of it to the third

  return 0;
}
