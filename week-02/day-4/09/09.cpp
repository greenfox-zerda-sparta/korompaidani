#include <iostream>

using namespace std;

void stardrawer(int input) {
  char star = '*';
  char space = ' ';
  int originput = input;
  input = input * 2;
  int spaces = input * 2 -1;
  for (int j = 1; j <= input - 2; j = j + 2){
    for (int i = spaces - input - originput + 1; i > 0; i --) {
      cout << space;
    }
    for (int i = 0; i < j; i ++) {
      cout << star;
  }
  cout << endl;
  spaces--;
  }
    for (int j = input - 1; j >= 1; j = j - 2){
    for (int i = spaces - input - originput + 1; i > 0; i --) {
      cout << space;
    }
    for (int i = 0; i < j; i ++) {
      cout << star;
  }
  cout << endl;
  spaces++;
  }
}

int main() {
  // Create a function that takes a number and prints a diamond like this:
  //
  //      *
  //     ***
  //    *****
  //   *******
  //  *********
  // ***********
  //  *********
  //   *******
  //    *****
  //     ***
  //      *
  //
  // The diamond should have as many lines as the value in the argument
  int howmany;
  cout << "Give me a number: ";
  cin >> howmany;
  stardrawer(howmany);
  return 0;
}
