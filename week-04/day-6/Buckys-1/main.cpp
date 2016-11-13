#include <iostream>
#include "Mother.h"
#include "Daughter.h"

using namespace std;

int main()
{
  cout << "This is the top of the projects main";
  Mother mom;
  mom.sayName();

  Daughter tina;
  tina.sayName();

  return 0;
}
