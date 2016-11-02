#include <iostream>

using namespace std;
/*
int* fill_array_with_fives(int* arr) {
  for(int i = 0; i < 5; i++) {
    arr[i] = 5;
  }
}*/
int* create_array_with_fives() {
  int* array = new int[5];
  for(int i = 0; i < 5; i++) {
    array[i] = 5;
  }
  return array;
}

int main() {
  //int array[] = {5, 5, 5, 5, 5};
  //int* array = new int[5];

  //fill_array_with_fives(array);
  int* array = create_array_with_fives();

 /* for(int i = 0; i < 5; i++) {
    array[i] = 5;
  }*/



  for(int i = 0; i < 5; i++) {
    cout << array[i] << endl;
  }

  delete[] array;

  return 0;
}
