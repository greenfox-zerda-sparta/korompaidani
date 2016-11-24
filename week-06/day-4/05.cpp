#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pback(vector<char>& input, char in_char) {
  input.push_back(in_char);
}

int main() {

  vector<char> chv(0);

  pback(chv, 'a');

  cout << chv[0] << endl;

	//create a vector of chars with the size of zero;
	//write a function where the user can add characters to the end of this vector

  return 0;
}
