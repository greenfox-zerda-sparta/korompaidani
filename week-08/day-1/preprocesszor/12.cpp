// Take the function like macro from the previous exercise.
// Make it so, that it's defined like the way You wrote it
// when __DEBUG is defined.
// It's defined to be nothing otherwise.

#include <iostream>

using namespace std;

#ifdef __DEBUG
#define myfunction(x) if(!(x)) {cout << "The expression in the argument: " << x << ", in: " << __FILE__ << ", at: " << __LINE__ << endl;}
#else
#define myfunction(x)
#endif

int main() {

  int x = 4;
  myfunction(x > 5);
  system("pause");
  return 0;
}