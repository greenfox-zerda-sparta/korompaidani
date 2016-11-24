#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void last_item_add_to_randomwhere(vector<double>& input) {
  unsigned int i = rand() % input.size();
  input.at(i) += input.back();
}

int main() {

  vector<double> my_vector(30, 1.5);

  srand (time(NULL));

  last_item_add_to_randomwhere(my_vector);

  for (unsigned int i = 0; i < my_vector.size(); i++) {
    cout << i + 1 << ". element: " << my_vector[i] << endl;
  }

	//create a vector of doubles with the size of 30, with every element equal of 1.5
	//create functions that takes this vector, pick the last element of it and adding its value to
	//an other item from the vector(this item place is random) and remove the last element at the end
	//run this function 20 times, then print every element of the vector

  return 0;
}
