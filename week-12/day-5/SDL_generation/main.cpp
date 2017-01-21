#include <iostream>
#include <string>
using std::cout;
using std::endl;

void coord_generator(int _beg, int repeat, int x, int z, char ax) { //x,z, must be 0 and ax 'x' at calling 
  int beg = _beg;
  int end = beg + 2;

  for (int j = beg + z; j < end + z; j++) {
    for (int i = beg + x; i < end + x; i++) {
      cout << "(" << j << ", " << i << ")" << endl;
    }
  }
  cout << endl;
  switch (ax) {
  case 'x':
    x++;
    ax = 'z';
    break;
  case 'z':
    z++;
    ax = 'd';
    break;
  case 'd':
   // x++;
   // z++;
    //beg++;
    ax = 'x';
    break;
  }
  repeat--;
  if (repeat < 0) {
    return;
  }
  else {
    coord_generator(-2, repeat, x, z, ax);
  }
}

int main(int argc, char* argv[]) {
  coord_generator(-2, 3, 0, 0, 'x');
  /*int beg = -2;
  int end = beg + 2;
  int x = 0;
  int z = 0;

  for (int j = beg + z; j < end + z; j++) {
    for (int i = beg + x; i < end + x; i++) {
      cout << j << ", " << i << endl;
    }
  }
  */
  /*diagonal shift*/
  //beg++;
  //end++;
  /*axis z shift*/
  //z++;
  /*axis x shift*/
  //x++;

  return 0;
}