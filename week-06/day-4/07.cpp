#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {

  vector<int> v(20);

  for (unsigned int i = 0; i < v.size(); i++) {
    v[i] = rand() % 10;
  }

  for (unsigned int i = 0; i < v.size(); i++) {
    cout << "normal content: " << v[i] << endl;
  }

  for (unsigned int i = 0; i < v.size(); i++) {
    if ((v[i] % 2) == 0) {
      v.erase(v.begin() + i);
    }
  }

  for (unsigned int i = 0; i < v.size(); i++) {
    cout << "without even numbers: " << v[i] << endl;
  }

	//create a vector of integers with the size of 20
	//fill this vector with random numbers from 0 to 10
	//print the items of the vector
	//remove the even numbers, then print the items again

  return 0;
}
