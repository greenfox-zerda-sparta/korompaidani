#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {

  vector<int> v1(10);

  for (unsigned int i = 0; i < v1.size(); i++) {
    v1[i] = 1 + rand() % 10;
    cout << v1[i] << endl;
    srand (time(NULL));
  }

	//Create a vector of integers
	//reserve place for 10 element, then fill those place with random numbers between 0 and 10

  return 0;
}
