#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int main() {
    // Create a `Stack` class that stores elements
    // It should have a `size` method that returns number of elements it has
    // It should have a `push` method that adds an element to the stack
    // It should have a `pop` method that returns the last element form the stack and also deletes it from it
  double input[5] = {1, 2, 3, 4, 5};
  int size = 5;

  Stack s1(input, size);
  s1.get_Stack_data();
  s1.stack_push(7);
  s1.get_Stack_data();
  s1.stack_pop();
  s1.get_Stack_data();
  cout << endl <<"The actual size is:" << s1.get_size();
  return 0;
}
