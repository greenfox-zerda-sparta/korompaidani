// Create a function like macro, that gets an expression as it's input.
// If the expression is false, it should print out some error message.

#include <iostream>

#define get(a) {a ? std::cout << #a : std::cout << "Error" ;}

int main8() {
  int a = 12;
  int b = 27;

  get(b < a);
  system("pause");
  return 0;
}