#include <iostream>
#include <string>

using namespace std;

int fibonacci(int n) {
  if ((0 == n) || (1 == n)) {
    return n;
  }
  else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int main() {
  for (int i = 0; i < 10; i++) {
    cout << fibonacci(i) << endl;
  }
  system("pause");
  // We have reindeers standing in a line, numbered 1, 2, ... The odd reindeers 
  // (1, 3, ..) have the normal 2 antlers. The even reindeers (2, 4, ..) we'll say 
  // have 3 antlers, because they each have a raised branch (how funny they are, arent they?).  
  // Recursively return the number of "antlers" in the reindeer line 1, 2, ... n (without loops or 
  // multiplication).

  return 0;

}