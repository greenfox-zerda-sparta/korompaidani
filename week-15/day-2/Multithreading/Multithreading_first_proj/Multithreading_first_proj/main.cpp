#ifndef TEST
#include <iostream>
#include <vector>
#include <algorithm>
//#include <iterator>
#include <utility>

using std::cout;
using std::endl;
using std::vector;
bool descend(int i, int j);
bool find_number_in_container(vector<int> container, int number);

int main(int argc, char* argv[]) {

  int my_array[8] = { 3, 44, 2, 65, 32, 4, 12, 9 };
  vector<int> my_vector(my_array, my_array + 8);
  std::sort(my_vector.begin(), my_vector.end(), descend);

  cout << find_number_in_container(my_vector, 45) << endl;

  return 0;
}

bool descend(int i, int j) {
  return (i > j);
}

bool find_number_in_container(vector<int> container, int number) {
  if (container[container.size() / 2] == number) {
    return true;
  }
  else {
    if (container.size() != 1) {
      if (container[container.size() / 2] > number) {
        container.erase(container.begin(), container.begin() + container.size() / 2);
      }
      else {
        container.erase(container.begin() + container.size() / 2, container.end());
      }
      return find_number_in_container(container, number);
    }
    else {
      return false;
    }
  }
}

#endif