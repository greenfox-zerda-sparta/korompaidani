#include <iostream>
#include <fstream>
#include <string>
#include "Tool.hpp"

using namespace std;

int main() {

  string file1 = "encrypted.txt";
  cout << reverse_lines_from_and_print(file1);

  // Create a program that decrypts the file called "reversed-lines.txt",
  // and pritns the decrypred text to the terminal window.

  return 0;
}
