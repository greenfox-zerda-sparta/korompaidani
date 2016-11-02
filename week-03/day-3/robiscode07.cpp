/*
 * 07.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: robertwinke
 */


/**
 * Create a function called "union" that takes two pointers to int arrays, and their sizes.
 * It should also take an output pointer and size as reference.
 * The output pointer should point to a new array that only consists the union of the two arrays.
 * The size should be the size of the new array.
 */

#include <iostream>

using namespace std;

bool contains(int* output, int new_size, int number){
  bool answer = false;

  for (int i = 0; i < new_size; i++) {
    if (output[i] == number) {
      answer = true;
    }
  }
  return answer;
}

int* resize(int* pointer, int size, int new_size) {
  int* new_pointer;
  new_pointer = new int[new_size];

  for (int i = 0; i < new_size; i++){
    if (i < size) {
      new_pointer[i] = pointer[i];
    }
  }
  delete[] pointer;

  return new_pointer;
}

int* unionfunc(int* array1, int* array2, int size1, int size2) {
  int* output_pointer;
  int new_size = size1 + size2;
  output_pointer = new int[new_size];
  int j = size1;

  for (int i = 0; i < size1; i++) {
    output_pointer[i] = array1[i];
    //cout << "dfhdf" << endl;
  }

  for (int i = 0; i < new_size; i++) {
    if (!contains(output_pointer, new_size, array2[i])) {
      //cout << "yay" << endl;
      output_pointer[j] = array2[i];
      j++;
    }
  }

  output_pointer = resize(output_pointer, new_size, j-size1);

  return output_pointer;
}

int main() {

  int array1[5] = {3,5,7,8,9};
  int array2[5] = {4,9,12,5,8};
  int* unionarray;

  unionarray = unionfunc(array1, array2, 5, 5);

  for (int i = 0; i < 7; i++) {
    cout << unionarray[i] << endl;
  }

  delete[] unionarray;


  return 0;
}

