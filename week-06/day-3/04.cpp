#include <iostream>
#include <string>

using namespace std;

template <class dani>
dani order_descend(dani* array, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (array[i] < array[j]) {
        dani temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

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
  char* arr_char_star[3] = {"ab", "bb", "aa"};
  //string arr_string[3] = {"oh", "yeah", "huh"};

  order_descend(arr_int, 3);
  order_descend(arr_float, 3);
  order_descend(arr_char, 3);
  order_descend(arr_char_star, 3);

  print_array(arr_int, 3);
  print_array(arr_float, 3);
  print_array(arr_char, 3);
  print_array(arr_char_star, 3);

	// create a function template that takes an array and sort it in a descending order

  return 0;
}
