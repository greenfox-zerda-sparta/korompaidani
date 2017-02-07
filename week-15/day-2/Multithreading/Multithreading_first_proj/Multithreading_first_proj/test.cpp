#ifdef TEST

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  
  int num = 1;
  cout << &num << endl;
  int* pointer = &num;

  cout << pointer << endl;
  cout << *pointer << endl;

  int* pointer2 = pointer;




  cout << pointer2 << endl;

  return 0;
}

#endif