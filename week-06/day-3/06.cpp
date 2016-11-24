#include <iostream>
#include <string>

using namespace std;

template <class dani>
dani sum_of_array(dani* array, int size) {
  dani temp = dani();
  for (int i = 0; i < size; i++) {
    temp += array[i];
  }
  return temp;
}

int main() {

  int arr_int[3] = {7, 8, 4};
  float arr_float[3] = {7.6, 3.8, 2.4464};
  char arr_char[3] = {'d', 'a', 'n'};

  char* arr_char_star[3] = {"oh", "yeah", "huh"};
  string arr_string[3] = {"oh", "yeah", "huh"};

  cout << sum_of_array(arr_float, 3);

for (int i = 0; )

  // Create a function template that takes an array, and its length and return the sum of his elements
  // Create a template specialization for char types, that it returns the sum of the characters integer position in the alphabet
  // Create a template specialization for string types, that it returns the sum of the string's first characters position in the alphabet

  return 0;
}
