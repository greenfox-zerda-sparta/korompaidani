#include <iostream>

using namespace std;

int main() {
  int* pointer = new int[5];

  // Please allocate a 10 long array and fill it with numbers from 0 to 9, then print the whole array
  // Please delete the array before the program exits

  for(int i = 0; i < 10; i++) {
  cout << pointer[i] << " ";
  }

  delete[] pointer;

  pointer = new int[10];
  int j = 0;
  for(int i = 0; i < 10; i++) {
    pointer[i] = i;
  }

  for(int i = 0; i < 10; i++) {
  cout << endl << pointer[i] << " ";
  }

  delete[] pointer;

  for(int i = 0; i < 10; i++) {
  cout << pointer[i] << " ";
  }

  return 0;
}
