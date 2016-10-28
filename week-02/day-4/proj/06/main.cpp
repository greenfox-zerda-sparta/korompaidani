#include <iostream>
#include <string>

using namespace std;

int evenfeven(int* input, int length) {
  int evcounter = 0;
  int a =0;
  for (int i = 1; i < length; i ++) {
    input [i - 1] % 2 == 0 && input [i] % 2 == 0 ? evcounter ++ : a ++;;
  }
  return evcounter;
}

int main() {
  int numbers[] = {5, 2, 6, 3, 4, 8, 5, 2, 2, 2};

  // Write a function that counts how many times is an even number is folowed by
  // another even number in an array

  int length = sizeof(numbers) / sizeof(int);
  cout << evenfeven(numbers, length) << " times" << endl;

  return 0;
}
