#include <iostream>
#include <string>

using namespace std;

int count_down(int n) {
  if (n == 0) {
    return 0;
  }
  else {
    cout << n-- << endl;
    return count_down(n);
  }
}

int main1() {

  count_down(11);
  system("pause");
  // write a recursive function
  // that takes one parameter: n
  // and counts down from n

  return 0;

}

