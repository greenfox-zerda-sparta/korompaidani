#include <iostream>
#include <string>

using namespace std;
/*
my first version I leave this in my code due to educational purposes
int sum_digits(unsigned int n, int z) {
  if (n / 10 > 0) {
    z += n % 10;
    n = n / 10;
    return sum_digits(n, z);
  }
  else {
    return z += n % 10;
  }
}
*/

int sum_digits(unsigned int n) {
  if (n / 10 > 0) {
    return n = sum_digits(n / 10) + n % 10;
  }
  else {
    return n;
  }
}

int main3() {
  unsigned int input;
  
  do {
    cin >> input;
    cout << sum_digits(input) << endl;
  } 
  while (input != 0);

  // Given a non-negative int n,
  // return the sum of its digits recursively (no loops).
  // Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6),
  // while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).

  return 0;

}