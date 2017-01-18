#include <iostream>
#include <string>

using namespace std;

int powerN(int x, int n) {
  if (n == 1) {
    return x;
  }
  else {
    n--;
    return powerN(x, n) * x;
  }
}

int main4() {

  cout << powerN(3, 3) << endl;
  system("pause");

  // Given base and n that are both 1 or more, compute recursively (no loops)
  // the value of base to the n power, so powerN(3, 2) is 9 (3 squared).

  return 0;

}