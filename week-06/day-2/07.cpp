#include <iostream>
#include <string>
#include <exception>
using namespace std;

// Write a function that can throw two kinds of exceptions: int and const char*
// It should receive an integer.
// It should return a string from the char* array defined below.
// If the integer is larger than 5, throw an integer exception. The value of the exception should be how much larger it is.
// If the integer is less than 0, it should throw a const char* exception stating, that it is a negative number.
//
// Illustrate both cases in the main function.
// HINT: Put each protected code segmetn in a new try-catch block.

string string_from_char_element(int index) throw(int, const char*) {
  const char* sentence[6] = {"What", "a", "pleasant", "surprise", "this", "is."};
  if (index < 0) {
    throw "You gave a negative number as an index.";
  }
  else if (index > 5) {
    throw index - 5;
  }
  else {
    return sentence[index];
  }
}

int main () {

  try {
    cout << string_from_char_element(4);
  }
  catch (int ex_int) {
    cout << "The exception is: " << ex_int << endl;
  }
  catch (const char* ex_char_star) {
    cout << "The exception is: " << ex_char_star << endl;
  }

  return 0;
}
