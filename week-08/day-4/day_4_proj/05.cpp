#include <iostream>
#include <string>

using namespace std;

int ear_counter(int bunny) {
  if (bunny == 0) {
    return 0;
  }
  else {
    return 2 + ear_counter(bunny - 1);
  }
}

int main5() {

  cout << ear_counter(3);
  system("pause");

  // We have a number of bunnies and each bunny has two big floppy ears.
  // We want to compute the total number of ears across all the bunnies
  // recursively (without loops or multiplication).

  return 0;

}