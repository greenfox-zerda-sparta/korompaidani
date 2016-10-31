#include <iostream>

using namespace std;

void stardrawer(int input) {
  char star = '*';
  string stars = "*";
  for (int j = 1; j <= input; j ++){
    for (int i = 0; i < j; i ++) {
      cout << star;
  }
  cout << endl;
  }
}

int main() {
  // create a function that takes a number and prints a triangle like this:
  // *
  // **
  // ***
  // ****
  // *****
  // ******
  //
  // The triangle should have as many lines as the value in the argument
  int howmany = 3;
  stardrawer(howmany);
  return 0;
}
