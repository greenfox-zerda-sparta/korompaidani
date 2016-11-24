#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  vector<int> v1(5);
  unsigned int v1_s = v1.size();

  for (unsigned int i = 0; i < v1_s; i++) {
    cout << v1[i] << endl;
  }

	//create an integer vector with the size of 5 and print all elements of it

  return 0;
}
