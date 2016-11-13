#include <iostream>
#include "Mother.h"

using namespace std;

Mother::Mother() {

}

void Mother::sayName() {
  cout << "I am the Mother" << endl;
}

void Mother::mother_priv_setter(int input) {
  privatev = input;
};

void Mother::mother_prot_setter(int input) {
  protectedv = input;
};

void Mother::get_mother_priv_n_prot() {
  cout << "This is mother's privatev: " << privatev << endl;
  cout << "This is mother's protectedv: " << protectedv << endl;
};
