#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

  ifstream my_file;
  string lines;
  my_file.open("fifth-exercise.txt");
  if (!my_file.is_open()) {
    cout << "Could not open the file" << endl;
    return 2;
  }
  else  {
    while (my_file >> lines) {
      cout << lines << endl;
    }
    my_file.close();
    return 0;
  }
  // Write a program that prints a content of a file called "fifth-exercise.txt"
  // If it could not open the file it should write: "Could not open the file" to the standard error
  // The program should return 2 if there where an error
}
