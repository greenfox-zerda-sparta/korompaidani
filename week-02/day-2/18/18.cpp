
#include <iostream>
using namespace std;

int evens(int length, int[]);

int main(){
  int numbers[] = {4, 5, 6, 2, 3, 8, 6, 5};
  // create a function that takes an array and it's length as an agrument
  // and returns a number that states how many even numbers are in the array
  int length = sizeof(numbers) / sizeof(int);
  cout << evens(length, numbers);

	return 0;
}

int evens(int length, int numbers[]){
    int evcount=0;
    for (int i=0; i < length; i++){
        if(numbers[i]%2==0){
            evcount++;
        }
    }
    return evcount;
}
