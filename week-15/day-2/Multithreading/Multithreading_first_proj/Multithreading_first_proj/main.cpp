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
  
  cout << "true is 1: " << find_number_in_container(my_vector, 44) << endl;

  return 0;
}

bool descend(int i, int j) {
  return (i > j);
}

bool find_number_in_container(vector<int> container, int number) {  

  
  int size = container.size();
  if (number > container[0] || number < container[size - 1]) {
    return false;
  }
  else {
    while (size != 2) {
      size /= 2;
      if (number >= container[(size)-1]) {
        cout << "first part" << endl;
        vector<int>::iterator it = container.begin();
        //container = 
        if (container[0] == number) {
          cout << "yes" << endl;
        }
      }
      else {
        cout << "second part" << endl;
        if (container[size - 1] == number) {
          cout << "yes" << endl;
        }
      }
    }
  }
  return true;
}

#endif