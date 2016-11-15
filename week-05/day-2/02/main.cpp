#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream my_file;
  string file_content;
  string line;

  my_file.open("second-exercise.txt");

  while (my_file >> line) {
    file_content += line + '\n';
  };
  cout << file_content;

  my_file.close();

  // Open a file called "second-exercise.txt"
  // Read the content of the file and print it to the terminal window

  return 0;
}
