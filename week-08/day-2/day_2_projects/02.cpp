#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// create a function that prints a vector using iterators
void print_vector_content(vector<int>& in_v) {
  for (vector<int>::iterator it = in_v.begin(); it != in_v.end(); it++) {
    cout << *it << endl;
  }
}

int main2() {
  vector<int> v;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }

  print_vector_content(v);
  system("pause");
  return 0;
}