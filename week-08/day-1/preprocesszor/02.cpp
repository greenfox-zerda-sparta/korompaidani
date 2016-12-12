#include <iostream>
#define MY_CONST 3
using namespace std;

int main2() {

  std::cout << MY_CONST << std::endl;
#undef MY_CONST
#define MY_CONST 5
  std::cout << MY_CONST << std::endl;

  // Create a constant using a prepocesor directive.
  // Print it out to the console.
  // Undefine it. And then redefine it with a new value.
  // Print it out again.

  system("pause");

  return 0;
}