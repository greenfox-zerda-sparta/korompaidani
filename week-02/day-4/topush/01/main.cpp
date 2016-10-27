#include <iostream>
#include <string>

using namespace std;

void squares (int* array, int length) {
  for (int i = 0; i < length; i ++) {
    array [i] *= array [i];
  }
}

int main(int argc, char** argv) {
  // Write a function that takes an array and squares all the elements in the array
  int array [] = {1, 2, 3, 4, 5, 6, 7};

  int length = sizeof(array) / sizeof(int);

  squares(array, length);

  for (int i = 0; i < length; i ++) {
    cout << array [i] << endl;
  }


  return 0;
}
