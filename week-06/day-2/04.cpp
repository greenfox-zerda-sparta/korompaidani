#include <iostream>
#include <string>
using namespace std;

string* split_string(string input, unsigned int index) throw(const char*){
  if (input.length() > index) {
    string* splitted_string = new string[2];
    for (unsigned int i = 0; i < index; i++) {
      splitted_string[0] += input[i];
    }
    for (unsigned int i = index; i < input.length(); i++) {
      splitted_string[1] += input[i];
    }
    return splitted_string;
  }
  else {
    throw "Index is out of bounds!";
  }
}

int main() {
  try {
    cout << "Function working:" << endl;
    for (int i = 0; i < 2; i++) {
      cout << split_string("Rebarbara", 2)[i] << " ";
    }
    cout << endl << endl << "Function throw exception:" << endl;
    for (int i = 0; i < 2; i++) {
      cout << split_string("Rebarbara", 9)[i] << " ";
    }
  }
  catch (const char* excp) {
    cout << "Error mess is : " << excp;
  }
  return 0;
}

// Write a function that receives a string and an unsigned integer.
// The function should return an array of strings, with two string in it.
// The first string should be the first part of the original string
// Characters in range [0,index-1].
// The second part should be the rest of the string characters range [index,length-1]
// Example: split("Rebarbara", 2)
// Result: {"Re", "barbara"}
// If the index is out of bounds, throw an exception.

// In the main function demonstrate the function when working, and when throwing an exception.
// Write the results to the console.
