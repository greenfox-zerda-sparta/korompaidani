#include <iostream>
#include "Mother.h"
#include "Daughter.h"

using namespace std;

int main()
{
  Mother mom;
  mom.sayName();

  Daughter tina;
  tina.sayName();

  tina.mother_priv_setter(5);
  tina.mother_prot_setter(7);
  //tina.prot_setter(8);

  tina.get_mother_priv_n_prot();

  return 0;
}
