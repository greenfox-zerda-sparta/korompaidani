#include <iostream>
#include <exception>

using namespace std;

int main() {
  try {
    throw 20;
  }
  catch (int x) {
    cout << "error code: " << x << endl;
  }

  return 0;
}

// Write a try - catch block.
// Throw an integer in the try block
// Catch it in the catch block and write it out.
