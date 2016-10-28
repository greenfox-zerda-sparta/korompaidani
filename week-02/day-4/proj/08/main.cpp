#include <iostream>

using namespace std;

void stardrawer(int input) {
  char star = '*';
  char space = ' ';
  int originput = input;
  input = input * 2;
  int spaces = input * 2 -1;
  for (int j = 1; j <= input; j = j + 2){
    for (int i = spaces - input - originput; i > 0; i --) {
      cout << space;
    }
    for (int i = 0; i < j; i ++) {
      cout << star;
  }
  cout << endl;
  spaces--;
  }
}

int main() {
  // Create a function that takes a number and prints a triangle like this:
  //
  //      *
  //     ***
  //    *****
  //   *******
  //  *********
  // ***********
  //
  // The triangle should have as many lines as the value in the argument


  int howmany;
  cout << "Give me a number: ";
  cin >> howmany;
  stardrawer(howmany);

  return 0;
}
