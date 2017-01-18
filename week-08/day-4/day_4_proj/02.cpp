#include <iostream>
#include <string>

using namespace std;

int add_one(int n) {
  if (n == 0) {
    return 0;
  }
  else {
    n--;
    cout << n << endl;
    return n + add_one(n);
  }
}

int main2() {

  cout << add_one(6);
  system("pause");
  // write a recursive function
  // that takes one parameter: n
  // and adds numbers from 1 to n

  return 0;

}