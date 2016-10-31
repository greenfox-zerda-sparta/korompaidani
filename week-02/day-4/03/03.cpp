#include <iostream>

using namespace std;

void swapper (int* numone, int* numtwo) {
  int temp = *numone;
  *numone = *numtwo;
  *numtwo = temp;
};

int main() {
  int first = 12;
  int second = 54;

  // Write a function that takes two int pointers and swaps the values where the pointers point

  cout << "This is first: " << first << endl << "This is second: " << second << endl;

  swapper(&first, &second);

  cout << "This is first: " << first << endl << "This is second: " << second << endl;
  return 0;
}
