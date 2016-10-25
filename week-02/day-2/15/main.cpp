#include <iostream>
#include <string>

using namespace std;

int finder (int length, int number, int []);

int main() {
  int numbers[] = {7, 5, 8, -1, 2};
  // Write a function that takes ana array, its length and a number
  // and it returns the index of the given number in the array.
  // It should return -1 if did not find it. (linear search)

  int number;
  cout << "Enter a number, it will be find in my array: ";
  cin >> number;
  cout << finder (sizeof(numbers) / sizeof(int), number, numbers) << endl;

  return 0;
}

int finder(int length, int number, int numbers[]){
  int answer=-1;
  for (int i = 0; i < length; i++){
    if (numbers[i]==number){
        answer=i;
        break;

    }
  }
  return answer;
}
