#include <iostream>

using namespace std;

/**
 * Create a function called "fliter_greater_than_5" that takes a pointer to an int array, and it's size.
 * It should return a pointer to a new array that only consists the numbers that are bigger than 5.
 */

int* filter_greater_than_5(int* arr, int&arr_size) {
  int new_arr_size = 0;
  for(int i = 0; i < arr_size; i++) {
    arr[i] > 5 ? new_arr_size++ : new_arr_size = new_arr_size;
  }

  int* new_arr_ptr = new int[new_arr_size];
  new_arr_size = 0;
  for(int i = 0; i < arr_size; i++) {

    if(arr[i] > 5) {
      new_arr_ptr[new_arr_size] = arr[i];
      new_arr_size++;
    }
  }
  arr_size = new_arr_size;
  return new_arr_ptr;
}

int main() {
  int arr[] = {1, 55, 7, 3, 2, 6};
  int arr_size = sizeof(arr) / sizeof(int);

  int* new_arr = filter_greater_than_5(arr, arr_size);

  for(int i = 0; i < arr_size; i++) {
    cout << new_arr[i] << endl;
  }
  delete[] new_arr;
  return 0;
}
