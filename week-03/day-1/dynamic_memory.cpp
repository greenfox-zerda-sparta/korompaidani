#include <iostream>

using namespace std;

int* create_array() {
 int* pointer = new int[5];
 pointer[0] = 1;
 pointer[1] = 2;
 pointer[2] = 3;
 pointer[3] = 4;
 pointer[4] = 5;

 return pointer;
}
/*
int* create_array() {
  int new_array[5] = {1, 2, 3, 4, 5};
  int* pointer = new_array; // 0 eleme az arraynek, arra mutat
  return pointer;
}
*/
void other() {
 int a[5] = {5, 6, 7, 8, 9};
}

int main() {
  int* array;
  array = create_array();
  other();
  cout << array[0] << " " << array[1] << endl;
  delete[] array;

  return 0;
}
