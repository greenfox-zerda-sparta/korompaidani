#include <iostream>
#include <exception>

using namespace std;

// Write the body of the function below.
// It should throw an exception when b is zero.
// Check the result.


float division(float a, int b) throw (int) {
  if (b == 0) {
    throw 0;
  }
  return a / b;
}

int main() {
	try {
		cout << "Divison result: " << division(1, 2) << endl;
		cout << "Division result: " << division(2, 0) << endl;
	}
	catch (int excp) {
		cout << "Exception: " << excp << endl;
	}
	return 0;
}
