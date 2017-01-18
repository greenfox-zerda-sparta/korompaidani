#include <iostream>
#include <string>
#include "Intlist.h"
#include "Stack.h"

using namespace std;

// Take the attached hpp and cpp files. Read them trough.
// Choose either IntArrayList or IntLinkedList and implement it.
// Write code here in a main function that uses it and tests it in edge cases as well.

int main() {
  int arr[3] = {1, 9, 3};
	IntList* theList = new Stack(arr, 3);//Your code starts here!
	cout << ((Stack*)theList)->getArrElement(1) << endl;
	int arr2[3];
  cout << ((Stack*)theList)->getArray() << endl;
  *arr2 = ((Stack*)theList)->getArray();
  cout << arr[0] << " | " << arr[1] << " | " << arr[2];
  return 0;
}
