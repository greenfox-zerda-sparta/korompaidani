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
  
  int my_array[8] = {3, 44, 2, 65, 32, 4, 12, 9};
  vector<int> my_vector(my_array, my_array + 8);
  std::sort(my_vector.begin(), my_vector.end(), descend);
  for (int i = 0; i < 8; i++) {
    cout << my_vector[i] << endl;
  }
  
  cout << "true is 1: " << find_number_in_container(my_vector, 9) << endl;

  return 0;
}

bool descend(int i, int j) {
  return (i > j);
}

bool find_number_in_container(vector<int> container, int number) {

  int size = container.size();
  if (number > container[0] && number < container[size - 1]) {
    cout << "why 36?" << endl;
    return false;
  }
  size /= 2;
  if (size < 2) {
    cout << "why 41?" << endl;
    return (number == container[size - 1]);
  }
  else {    
    if (number == container[size - 1]) {     
      cout << "why 46?" << endl;
      return true;
    }
    else if (number > container[size - 1]) {
      vector<int> temp;
      for (int i = 0; i < size; ++i) {
        cout << "first part" << endl;
        temp.push_back(container[i]);        
      }
      return find_number_in_container(temp, size);
    }
    else if (number < container[size - 1]) {
      vector<int> temp;
      for (int i = size - 1; i < size * 2; ++i) {
        cout << "second part" << endl;
        temp.push_back(container[i]);
      }
      return find_number_in_container(temp, size);
    }    
  }
}

#endif