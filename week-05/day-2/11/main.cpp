#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string reverse_lines_from_and_print(string filename) {
  ifstream input;
  string line;
  int line_counter = 0;
  input.open(filename.c_str());
  if (!input.is_open()) {
    cout << "Cannot open " << filename << '!';
  }
  else {
    while (getline(input, line)) {
      line_counter++;
    }
    int temp_counter = line_counter;
    int i = 0;
    string buffer[line_counter];
    string content[line_counter];
    while (getline(input, line)) {
      buffer[line_counter - 1] = line[i] + '\n';
      i++;
      line_counter--;
    }
    for (int i = 0; i < temp_counter; i++) {
      content[i] = buffer[i];
    }
  input.close();
  return *content;
  }
}

int main()
{
  string file1 = "encrypted.txt";
  cout << reverse_lines_from_and_print(file1);
}
