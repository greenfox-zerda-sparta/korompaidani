#include <iostream>
#include <stdlib.h>

using namespace std;

bool type_control(int realnum, int* controlnum) {
    for(int i = 0; i < 9; i++) {
      if(controlnum[i] == realnum) {
        return true;
        break;
      }
    }
    return false;
  };

int main()
{
  int realnum = 5;
  int controlnum [] = {1, 3, 4, 5, 0, 0, 0, 0, 0};

  do {
  cout << "The controlnums are the following: ";
  for (int i = 0; i < 9; i++) {
    cout << controlnum[i] <<" ";
  }
  cout << "\nPlease give me a num: ";
  cin >> realnum;
  type_control(realnum, controlnum) == true ? cout << "The " << realnum << " is exist in the array\n\n" :  cout << "The " << realnum << " does >>NOT<< exist in the array\n\n";
  }
  while (realnum != 42);

  return 0;
}
