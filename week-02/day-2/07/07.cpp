#include <iostream>
#include <string>

using namespace std;

int main() {
  char g1 = 'a';
  double g2 = 12.345;
  // Tell if g1 is stored in more bytes than g2

  cout << sizeof(g1) << endl;
  cout << sizeof(g2) << endl;

  if (sizeof(g1)>sizeof(g2)){
    cout << "g1 is stored in more bytes by " << g1 - g2 << " bytes" << endl;
  }

  return 0;
}
