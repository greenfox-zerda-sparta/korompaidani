#include <iostream>

using namespace std;

/**
 * Create a function called "resize" that takes a pointer to an int array, it's size and it's new size,
 * then it should return a new pointer that points to the new resized array.
 * It should copy all the elements to the new array, if the array is bigger it should fill all the new slots with zeros.
 * It should delete the old array.
 */
int* resize(int* array, int arrsize, int arr_newsize) {

  int* pointer = new int[arr_newsize];

  for(int i = 0; i < arr_newsize; i++) {
    pointer[i] = array[i];
    if(i >= arrsize) {
      pointer[i] = 0;
    }
  }
  return pointer;
}

int main() {
  int orig_array[] = {1, 2, 3, 4, 5};
  const int new_size = 9;
  int arrsize = sizeof(orig_array) / sizeof(int);
  int* resized_array = resize(orig_array, arrsize, new_size);

  for(int i = 0; i < 9;  i++) {
    cout << resized_array[i] << endl;
  }
  delete[] orig_array;
  return 0;
}
