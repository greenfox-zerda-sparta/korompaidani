#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
  srand(time(NULL)); // This initializes the random generator.
  int rnd = 0;
  for (int i = 0; i < 20; i++) {
    rnd = rand() % 5; // generate a random number in the range [0, 4]
    try {
      switch (rnd) {
        case 0:
          throw 3.2f;
          break;
        case 1:
          throw double(43.56);
          break;
        case 2:
          throw "Abrakadabra";
          break;
        case 3:
          throw false;
          break;
        default:
          throw 12;
          break;
      }
    }
    catch (float ex_float) {
      cout << "The exception type is float: " << ex_float << endl;
    }
    catch (double ex_double) {
      cout << "The exception type is double: " << ex_double << endl;
    }
    catch (const char* ex_char_star) {
      cout << "The exception type is a pointer to a string: " << ex_char_star << endl;
    }
    catch (bool ex_bool) {
      cout << "The exception type is boolean: " << ex_bool << endl;
    }
    catch (int ex_int) {
      cout << "The exception type is integer: " << ex_int << endl;
    }
  }
  return 0;
}

// Write catch blocks for each possibly thrown exception.
// In each catch block write out what the exception's type was. And what the exceptions value was.
