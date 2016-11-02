#include <iostream>

using namespace std;

/**
 * Please create a program that asks for a count when it starts.
 * It should ask for a number count times, then it shoud print the average of the nubmers.
 * It should delete any dynamically allocated resource before the program exits.
 */

float average() {
  float cont = 0;
  int countnum;
  cout << "Please enter a count number: ";
  cin >> countnum;
  float* pointer = new float[countnum];
  for(int i = 0; i < countnum; i++) {
    cout << "Enter the " << i+1 << ". number: ";
    cin >> pointer[i];
    cont = cont + pointer[i];
  }
  return cont / countnum;
  delete[] pointer;
}

int main() {
  cout << "The average of numbers is: " << average();
  return 0;
}
