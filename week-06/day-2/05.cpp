#include <iostream>
#include <string>
#include <exception>
#include <array>

using namespace std;

string* string_splitter_by_char(string input, char where) throw (const char*) {
  unsigned short int split_counter = 0;
  for (unsigned int i = 0; i < input.length(); i++) {
    if (input[i] == where) {
      split_counter++;
    }
  }
  if (split_counter == 0) {
    throw "The character doesn't exist in the sentence";
  }
  string* temp_arr = new string[split_counter + 1];
  int k = 0;
  for (unsigned int i = 0; i < input.length(); i++) {
    if (input[i] == where || i == input.length() - 1) {
      k++;
    }
    else {
      temp_arr[k] += input[i];
    }
  }
  temp_arr[k - 1] += input[input.length() - 1];
  return temp_arr;
}

int main() {
try {
  string sentence = "May the Force be with you!";
  string* address = string_splitter_by_char(sentence, 'x');

  for (int i = 0; i < address.size(); i++) {
    cout << address[i] << endl;
  }

  delete [] address;
}
catch (const char* ex) {
  cout << ex;
}

  return 0;
}

// Write a function that receives a string and a character.
// The function should return an array of strings.
// The function should split the string at the character it receives as the second argument.
// The character it uses to split should not be in any of the new strings.
// Example: split("What a nice day", ' ');
// Result: {"What", "a", "nice",  "day"}
// If the index is out of bounds, throw an exception.
// If the character is not in the string throw a different exception.
//
// In the main function demonstrate the function when working, and when throwing an exception.
// Write the results to the console.
