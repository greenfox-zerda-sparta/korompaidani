#include <iostream>
using namespace std;

bool prim(int input);

int main(){
  int number = 121;
  // create a function that decides if a number is a prime number.
  // It should take a number as an argument and return true if it is prime and
  // false otherwise.

  if (prim(number)==true){
    cout << "it's prim";
  }
  else{
    cout << "it's not prim";
  }

	return 0;
}

bool prim(int input){
    for (int i=2; i < input; i++){
        if (input % i == 0){
            return false;
        }
    }
    return true;
}
