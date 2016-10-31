#include <iostream>
#include <string>

using namespace std;

int dblmach (int input){
    int output=input*2;
    return output;
}

int main() {
  int j = 123;
  // create a function that doubles it's input
  // double j with it
  cout << dblmach(j);


  return 0;
}
