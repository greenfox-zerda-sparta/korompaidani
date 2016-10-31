#include <iostream>

using namespace std;

int main()
{

int asd[5] = {1235, 876544, 2, 125413642, -745};
  int *a =asd;
  char *b = (char*)asd;
  unsigned int *c = (unsigned int*)asd;
  cout << *a++ << " " << *a++ << " " << *a << endl;
  cout << *a++ << " " << *a << endl;

  cout << b[0] << b[1] << *b++ << endl;

  cout << "a-c adress: " << ((char *)a)-((char *)c) << endl;
  cout << "b-c adress: " << ((char *)b)-((char *)c) << endl;
  cout << "a-b adress: " << ((char *)a)-((char *)b) << endl; //cimuk kulonbsege, hany bajttal megy arrebb

  cout << c[4] << endl;
  cout << asd[4] << endl;
  cout << b[3] << endl;
  cout << (float)c[4] << endl;

  return 0;


}
