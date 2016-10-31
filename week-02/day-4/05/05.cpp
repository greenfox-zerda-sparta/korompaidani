#include <iostream>

using namespace std;

bool findneg(int* input, int length) {
  bool neg = false;
  for (int i = 0; i < length; i++) {
    if (input [i] < 0) {
      neg = true;
      break;
    }
  }
  return neg;
}

int main() {
  int numbers[] = {6, 5, 3, -4, -1, 8, 7};
  // Write a function that decides if an array includes at least one negative number or not

  int length = sizeof(numbers) / sizeof(int);
  cout << "The array contains at least one negative number. ";
  findneg(numbers, length) == 1 ? cout << "The statement is TRUE" : cout << "The statement is FALSE" << endl;
  return 0;
}
