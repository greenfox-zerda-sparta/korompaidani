#include <iostream>
#include <ctime>
#include <stdio.h>

using namespace std;

int main() {

const clock_t begin_time = clock();
// do something

  cout << "Time check" << endl;
  int array[100][100];
  int counter = 0;

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      array[j][i] = counter++;
    }
  }

std::cout << "clock is : " << float( clock () - begin_time ) /  CLOCKS_PER_SEC;

return 0;
}
