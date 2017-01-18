#include <iostream>


// Create a function like macro that takes an argumnet.
// It should print the the code of the argument and the value of the argument too.
// E.g.:
//
// #define FunctionLikeMacro(a) //here comes magic
// int Main() {
// 	int a = 23;
// 	FunctionLikeMacro(a);
//
// }
//
// Should have the output:
// Variable a = 23;
// Where both 'a' and '23' are set by teh macro.

#define FunctionLikeMacro(a) if(a) (std::cout << "Variable: " << #a << " = " << (a) )

int main10() {
  int a = 23;
  FunctionLikeMacro(a);
  system("pause");
  return 0;
}