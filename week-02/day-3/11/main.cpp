#include <iostream>
using namespace std;

void sortAscending(int *array, int length){
  for (int i = 0; i < length; i++){
    for (int j = i + 1; j < length; j++){
        if (array [j] < array [i]){
            int temp = array [j];
            array [j] = array [i];
            array [i] = temp;
        }
    }
  }
};
// Implement this function to sort the array in an ascending order.

void sortDescending(int *array, int length){
  for (int i = 0; i < length; i++){
    for (int j = i + 1; j < length; j++){
        if (array [j] > array [i]){
            int temp = array [j];
            array [j] = array [i];
            array [i] = temp;
        }
    }
  }
};
// Implement this function to sort the array in a descending order.

void printArray(int *array, int length) {
	cout << "{";
	for(int i=0; i<length; i++){
		cout << array[i];
		if(i<length-1) {
			cout << ", ";
		}
	}
	cout << "}" << endl;
}


int main(int argc, char** argv){
	int example[13] = {34, 56, 26, 84, 29, 3875, 43, 96, 4759, 979, 92, 56, 1987};
	sortAscending(example, 13);
	printArray(example, 13);
	sortDescending(example, 13);
	printArray(example, 13);

	return 0;
}
