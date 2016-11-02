#include <iostream>

using namespace std;

/**
 * Create a function called "union" that takes two pointers to int arrays, and their sizes.
 * It should also take an output pointer and size as reference.
 * The output pointer should point to a new array that only consists the union of the two arrays.
 * The size should be the size of the new array.
 */

int* unio(int* arr1, int* arr2, int&arr1_s, int&arr2_s, int&length) {
  length = arr1_s + arr2_s;
  int j = 0;
  int* arru_ptr = new int[length];
    for(int i = 0; i < length; i++) {
      if(i < arr1_s) {
        arru_ptr[i] = arr1[i];
      }
      else {
        arru_ptr[i] = arr2[j];
        j++;
      }
  }
  return arru_ptr;
}

int main() {

  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {6, 7, 88, 9};
  int arr1_s = sizeof(arr1) / sizeof(int);
  int arr2_s = sizeof(arr2) / sizeof(int);
  int length = 0;

  int* arr_unio = unio(arr1, arr2, arr1_s, arr2_s, length);

  for(int i = 0; i < length; i++) {
    cout << arr_unio[i] << endl;
  }
  delete[] arr_unio;
  return 0;
}
