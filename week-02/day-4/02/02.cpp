#include <iostream>

using namespace std;

void printer(int* array, int length) {
  for (int i = 0; i < length; i ++) {
    cout << array [i] << endl;
  }
};

void fillseries(int* array, int length) {
  for (int i = 0; i < length; i ++) {
    array [i] = i;
  }
}

int main(int argc, char** argv) {
  int array[10];

  // write a function that takes an array and a length and it fills the array
  // with numbers from zero till the length

  int length = sizeof(array) / sizeof(int);

  printer(array, length);
  fillseries(array, length);
  printer(array, length);


  return 0;
}
