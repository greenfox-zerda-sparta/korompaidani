#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

  ifstream my_file;
  string lines;

  my_file.open("fourth-exercise.txt");

  while (my_file >> lines) {
    cout << lines << endl;
  }

  // Open a file called "fourth-exercise.txt"
  // Print all of its lines to the terminal window

  return 0;
}
