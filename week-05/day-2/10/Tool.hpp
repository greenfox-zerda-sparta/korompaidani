#ifndef TOOL_H
#define TOOL_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string reverse_lines_from_and_print(string filename) {
  ifstream input;
  string line;
  string content;
  input.open(filename.c_str());
  if (!input.is_open()) {
    cout << "Cannot open " << filename << '!';
  }
  else {
    while (getline(input, line)) {
      string temp = line;
      int temp_length = temp.length() - 1;
      for (int i = 0; i < temp.length(); i++) {
        line[i] = temp[temp_length];
        temp_length--;
      }
      content += line + '\n';
    }
  }
  input.close();
  return content;
}

#endif // TOOL_H
