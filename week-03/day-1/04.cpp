#include <iostream>

using namespace std;

/**
 * Create a function called "range" that creates a new array and returns a pointer to it.
 * It should fill the array with numbers based on it's paramters.
 * It should take 3 paramters:
 * int from: the first number in the array
 * int to: it will fill the array till it would reach this number (so this number is not in the array)
 * int step: the step between the numbers
 *
 * Examples:
 * range(0, 10, 2) -> {0, 2, 3, 4, 5, 6, 8}
 * range(1, -8, -3) -> {1, -2, -5}
 *
 * It should delete any dynamically allocated resource before the program exits.
 */

int loop_size(int from, int to, int step) {
  int size;
  if(from > to) {
    size = from / step;
  }
  else {
    size = to / step;
  }
  (size < 0) ? size = size * (-1) : size = size;
  return size;
}

int* range(int from, int to, int step, int size) {
  int* pointer = new int[size];
  int temp = from;
  for(int i = 0; i < size; i++) {
    pointer[i] = temp;
    if(to < from) {
      temp = temp -  step;
    }
    else {
      temp = temp + step;
    }
  }
  return pointer;
}

int main() {
  int from = 15;
  int to = 5;
  int step = 3;

  int* array = range(from, to, step, loop_size(from, to, step));

  for(int i = 0; i < loop_size(from, to, step); i++) {
    cout << array[i] << endl;
  }

  delete[] array;

  return 0;
}
