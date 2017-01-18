// Define a function like macro that prints out the parameter it gets,
// and adds this string before it "DEBUG: " if __DEBUG is defined.
// Otherwise adds "RELEASE: " before the string.
// Use try it out. Illustrate that it works.

#include <iostream>

#ifdef __DEBUG
#define get(a){std::cout << "Debug: " << #a << " = " << a;}
#else
#define get(a){ std::cout << "Release: " << #a << " = " << a;}
#endif

int main5() {
  
  int b = 3;
  get(b);

  system("pause");
  return 0;
}