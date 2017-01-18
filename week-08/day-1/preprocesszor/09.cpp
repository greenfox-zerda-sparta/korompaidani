// Create a function like macro. The Macro should take one parameter and
// print out the parameter to the console after printing out in which file
// and at which line it has been called at.

#include <iostream>
#define print(a) {std::cout << "in " << __FILE__ << ": @line:" << __LINE__ << " " <<#a << std::endl;}

int main9() {
  int b = 7;
  print(b);
  system("pause");
  return 0;
}