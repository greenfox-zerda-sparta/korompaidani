#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void string_to_file(string filename, string content) {
  ofstream my_file(filename.c_str());
  my_file << content;
  my_file.close();
  cout << "File writer is complete!\n";
}

void print_file(string filename) {
  ifstream my_file;
  string content;
  string line;
  my_file.open(filename.c_str());
  if (!my_file.is_open()) {
    cout << "There's something wrong during opening your " << filename << "file!\n";
  }
  else {
    while (getline(my_file, line)) {
      content += line + '\n';
    }
    my_file.close();
    cout << content;
  }
}

int main() {

  string filename = "sample.txt";
  string content = "May the Force be with you!\nLuke I'm your father!";

  string_to_file(filename, content);
  print_file(filename);

  // Write a function that writes a string to a file
  // It should take the filename and the content as a string parameter

  return 0;
}
