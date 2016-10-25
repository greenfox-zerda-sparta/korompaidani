#include <iostream>
#include <string>

using namespace std;

int summer(int[]);

int main() {
  int numbers[] = {4, 5, 6, 7, 8, 9, 10};
  // write your own sum function
  // it should take an array and it's length

  cout << summer(numbers) << endl;

  return 0;
}

int summer(int in[]){
    int coll=0;
    for (int i=0; i < sizeof(in)/sizeof(int); i++){
        return coll+=in[i];
    }
}
