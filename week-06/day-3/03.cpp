#include <iostream>
#include <string>

using namespace std;

template <class dani>
dani print_array(dani* array, int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << endl;
  }
}

int main() {

  int arr_int[3] = {7, 8, 4};
  float arr_float[3] = {7.6, 3.8, 2.4464};
  char arr_char[3] = {'d', 'a', 'n'};
  string arr_string[3] = {"oh", "yeah", "huh"};
  char* arr_char_star[3] = {"oh", "yeah", "huh"};

  print_array(arr_int, 3);
  print_array(arr_float, 3);
  print_array(arr_char, 3);
  print_array(arr_string, 3);
  print_array(arr_char_star, 3);

	// create a function template which takes in an array, and the size of it
	// print all the elements of the array

  return 0;
}
