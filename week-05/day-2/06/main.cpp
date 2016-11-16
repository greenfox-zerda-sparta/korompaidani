#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char* char_star_to_string(string input) {
  char temp_char_star[input.length()];
  for (int i = 0; i < input.length(); i++) {
    temp_char_star[i] = input[i];
  }
  return temp_char_star;
}

string reader(string filename) {
  ifstream my_file;
  string lines;
  string content;
  my_file.open(filename.c_str());
  if (!my_file.is_open()) {
    return "Cannot not open " + filename + "!\n";
  }
  else {
    while (my_file >> lines) {
      content += lines + '\n';
    }
    my_file.close();
    return content;
  }
}

int main() {
  string filename1 = "variables.txt";
  string filename2;
  cout << reader(filename1);

  // Write a function that reads the content of a file and returns it as a string
  // It should take the filename as a string parameter

  return 0;
}
