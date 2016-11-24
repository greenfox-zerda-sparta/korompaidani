#include <iostream>
#include <string>

using namespace std;

template <class dani, class p>
dani which_is_larger_in_bytes(dani var1, p var2) {
  if (sizeof(var1) > sizeof(var2)) {
    cout << var1 << " is the bigger, it's size: " << sizeof(var1);
  }
  else if (sizeof(var1) < sizeof(var2)) {
    cout << var2 << " is the bigger, it's size: " << sizeof(var2);
  }
  else {
    cout << var1 << " and " << var2 << " sizes are same";
  }
}

int main() {

  int integer = 8;
  float floatt = 8;
  double doublet = 8;
  char character = '1';
  char* char_star = "1";

  which_is_larger_in_bytes(doublet, floatt);

  //Create a function template that takes 2 different typenames, and prints out
  //which one is stored in more bytes from then

  return 0;
}
