// Create a function like macro, that get's one parameter.
// This macro should print out that parameter using cout.
// Illustrate that it works in Your main function.

#include <iostream>

#define print(in) {std::cout << #in << " = " << in;}

int main7() {
  int my_int = 8;
  print(my_int);
  system("pause");
  return 0;
}