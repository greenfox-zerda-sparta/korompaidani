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

  int size_temp = 0;
  if(to < 0) {
    (size_temp = size_temp + to) * (-1);
  }
  int* pointer = new int[size + size_temp];
  int temp = from;
  for(int i = 0; i < size + size_temp; i++) {
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
  int from = 6;
  int to = 1;
  int step = 1;

  int* array = range(from, to, step, loop_size(from, to, step));

  for(int i = 0; i < loop_size(from, to, step); i++) {
    cout << array[i] << endl;
  }

  delete[] array;

/// 1- 10 if
/*

int size;
((from >= 0 && to >= 0) || (from <= 0 && to <= 0)) {
  size = (from - to) / step;
  size < 0 size * (-1) : size = size;
}

for(int i = 1; i <= 10; i++) {
    cout << i << endl;
}
cout << endl;

/// 10- 1
for(int i = 10; i >= 1; i--) {
    cout << i << endl;
}
cout << endl;

/// 5- -4
for(int i = 5; i >= -4; i--) {
    cout << i << endl;
}
cout << endl;

/// -3- 7
for(int i = -3; i <= 7; i++) {
    cout << i << endl;
}
cout << endl;

*/
  return 0;

}
