#include <iostream>
#include "Mother.h"
#include "Daughter.h"
using namespace std;

Daughter::Daughter() {

}

void Daughter::sayName() {
  cout << "Hello I am Daughter" << endl;
}

void Daughter::prot_setter(int input) {
  protectedv = input;
};

/*
void Daughter::priv_setter(int input) {
  privatev = input;
};
*/

void Daughter::mother_prot_setter(int input) {
  protectedv = input * 2;
};
