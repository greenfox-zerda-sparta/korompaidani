#include <iostream>

using namespace std;

void printer(int* array, int length) {
  for (int i = 0; i < length; i ++) {
    cout << array [i] << endl;
  }
}

void makerev(int* array, int length) {
  for (int i = 0; i < length; i ++) {
    int temp = array [i];
    array [i] = array [length-1];
    array [length-1] = temp;
    length --;
  }
}

int main() {
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
  // Write a function that takes an array and its length than reverses the array
  int length = sizeof(array) / sizeof(int);
  printer(array, length);
  makerev(array, length);
  printer(array, length);
  return 0;
}
