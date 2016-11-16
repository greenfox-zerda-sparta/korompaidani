#ifndef FUNCTIONTOOLS_H
#define FUNCTIONTOOLS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string file_to_string_entire(string filename) {
  ifstream my_file;
  string content;
  string line;
  my_file.open(filename.c_str());
  if (!my_file.is_open()) {
      cout << "Cannot open " << filename << '!';
  }
  else {
    while (getline(my_file, line)) {
      content += line + '\n';
    }
    my_file.close();
  }
  return content;
}

int file_line_counter(string filename) {
  ifstream my_file;
  string line;
  int line_counter = 0;
  my_file.open(filename.c_str());
  if (!my_file.is_open()) {
      cout << "Cannot open " << filename << '!';
  }
  else {
    while (getline(my_file, line)) {
      line_counter ++;
    }
    my_file.close();
  }
  return line_counter;
}

int adjust_int_to_frame(int number, int frame) {
  if (number > frame) {
    number = frame;
  }
  else if (number < 1) {
    number = 1;
  }
  else {
    number = number;
  }
  return number;
}

string file_to_string_from_to(string filename, int ent_lines, int from, int to) {
  ifstream my_file;
  string content;
  string line;
  int line_counter = 0;
  to = adjust_int_to_frame(to, ent_lines);
  from = adjust_int_to_frame(from, ent_lines);

  my_file.open(filename.c_str());
  if (!my_file.is_open()) {
      cout << "Cannot open " << filename << '!';
  }
  else {
    while (line_counter != to) {
      if (line_counter >= from - 1) {
        getline(my_file, line);
        content += line + '\n';
        line_counter++;
      }
      else {
        getline(my_file, line);
        line_counter++;
      }
    }
    my_file.close();
  }
  return content;
}

bool string_to_file(string filename, string input) {
  ofstream my_file;
  my_file.open(filename.c_str());
  if (!my_file.is_open()) {
    return false;
  }
  else {
    my_file << input;
    my_file.close();
    return true;
  }
}

//char char_star_to_char(char* input)

#endif // FUNCTIONTOOLS_H
