#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<int> v1;
  v1.push_back(1);

  cout << endl;
  for (unsigned int i = 0; i < v1.size(); i++) {
    cout << "This is |v1|: " << v1[i] << endl;
  }

  vector<int> v2(10, 5);
  v2.push_back(1);
  unsigned int v2_size = v2.size();

  cout << endl;
  for (unsigned int i = 0; i < v2_size; i++) {
    cout << "This is |v2| with size: " << v2[i] << endl;
  }

  for (unsigned int i = 0; i < v2.capacity(); i++) {
    cout << "This is |v2| with capacity: " << v2[i] << endl;
  }

  vector<int> v3;
  v3.reserve(20);
  v3.push_back(4);

  cout << endl;
  for (unsigned int i = 0; i < v3.size(); i++) {
    cout << "This is |v3| with size: " << v3[i] << endl;
  }

  for (unsigned int i = 0; i < v3.capacity(); i++) {
    cout << "This is |v3| with capacity: " << v3[i] << endl;
  }

  return 0;
}
