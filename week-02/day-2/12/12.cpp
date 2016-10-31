#include <iostream>
#include <string>

using namespace std;

int summer(int[], int length);

int main() {
  int numbers[] = {4, 5, 6, 7, 8, 9, 10};
  // write your own sum function
  // it should take an array and it's length
  int length = sizeof(numbers)/sizeof(int);
  cout << summer(numbers, length) << endl;

  return 0;
}

int summer(int in[], int length){
    int coll=0;
    for (int i=0; i < length; i++){
        coll+=in[i];
    }
    return coll;
}
