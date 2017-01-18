// Create a function like macro.
// It's job is to turn something written in code into a string.
// It should be called str(a).
// Try out the code below. See what happens!

#include <iostream>

#define str(a) #a

int main4() {
  int a = 24;
  int b = 21;
  if (a > b) {
    std::cout << str(a > b) << "  a: " << a << "  b: " << b << std::endl;
  }
  system("pause");
  return 0;
}

///csak akkor irodik ki, hogyha a feltetel igaz