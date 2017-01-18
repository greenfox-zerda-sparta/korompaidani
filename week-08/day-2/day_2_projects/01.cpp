#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm> 

using namespace std;

void print_content(int i) {
  cout << i << endl;
}

int main1() {
  vector<int> v;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }

  for (vector<int>::iterator it = v.begin(); it < v.begin() + 5; it++) {
    cout << *it << endl;
  }
  ///fuck yeah!!! :)
  for_each(v.begin(), v.begin() + 5, print_content);
  // Print the first 5 elements of the vector using iterators
  system("pause");

  return 0;
}