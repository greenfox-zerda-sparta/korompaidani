#include <iostream>

using namespace std;

int main()
{
  int controlnumb = 9;
  int numbers[] = {1, 2, 5, 3, 4};
  int outnumbs[] = {0, 0, 0, 0, 0};

  int temp;
  int init = 0;

  bool  exist = true;
  for(int i = 0; i < 5; i ++) {
    if (numbers[i] == controlnumb) {
      exist = true;
      break;
    }
    else {
      exist = false;
      temp = controlnumb;
    }
  }
  if (exist == false) {
    outnumbs[init] = temp;
    }
  init++;

  controlnumb = 3;
  exist = true;
  for(int i = 0; i < 5; i ++) {
    if (numbers[i] == controlnumb) {
      exist = true;
      break;
    }
    else {
      exist = false;
      temp = controlnumb;
    }
  }
  if (exist == false) {
    outnumbs[init] = temp;
    }
  init++;





  for(int i = 0; i < 5; i ++) {
   cout << outnumbs[i] << ' ';
  }






    return 0;
}
