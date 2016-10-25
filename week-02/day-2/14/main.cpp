#include <iostream>
#include <string>

using namespace std;

int minimaler(int length, int[]);

int main() {
  int numbers[] = {7, 5, 8, -1, 2};
  // Write a function that takes ana array and its length returns the minimal element
  // in the array (your own min function)

  int length = sizeof(numbers) / sizeof(int);
  cout << minimaler(length, numbers);

  return 0;
}

int minimaler(int length, int numbers[]){
  for (int i=0; i < length; i++) {
    for (int j = i + 1; j < length; j++) {
      if(numbers [j] < numbers [i]) {
            int temp = numbers [i];
            numbers [i] = numbers [j];
            numbers [j] = temp;
        }
    }
  }
  return numbers[0];
}
