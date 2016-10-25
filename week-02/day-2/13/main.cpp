#include <iostream>
#include <string>

using namespace std;

int factorial (int input);

int main() {
  // create a function that returns it's input factorial

    int n;

    cout<<"Please enter a number: ";
    cin>>n;
    cout << n << "! = " << factorial(n) << endl;

  return 0;
}

    int factorial(int input){
        if(input == 1) {
            return 1;
        }
        else {
            return input * factorial (input - 1);
        }
    }

