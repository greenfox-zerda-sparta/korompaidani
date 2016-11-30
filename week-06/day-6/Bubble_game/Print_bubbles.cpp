#include "Print_bubbles.hpp"
#include <iostream>

#include "Bubbles.hpp"

using namespace std;

Print_bubbles::Print_bubbles() {

}

void Print_bubbles::print_two_dim_vect(Bubbles b) {
  for (unsigned int j = 0; j < matrix.size(); j++) {
    cout << "|";
    for (unsigned int i = 0; i < matrix[j].size(); i++) {
      cout << matrix[j][i];
    }
    cout << "|" << endl;
  }
  cout << endl;
}
