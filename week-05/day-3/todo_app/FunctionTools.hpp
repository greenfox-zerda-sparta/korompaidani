#ifndef FUNCTIONTOOLS_H
#define FUNCTIONTOOLS_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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
  //to = adjust_int_to_frame(to, ent_lines);
  //from = adjust_int_to_frame(from, ent_lines);

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

bool empty_file(string filename) {
  ofstream my_file;
  my_file.open(filename.c_str());
  if (!my_file.is_open()) {
    return false;
  }
  else {
    my_file << '!';
    my_file.close();
    return true;
  }
}

string* char_star_array_to_string_array(char** input, int size) {
  string* temp_array = new string[size];
  int j = 0;
  for (int i = 1; i <= size; i++) {
    temp_array[j++] = input[i];
  }
  return temp_array;
}

bool is_it_valid_typing_for_first_element(string input) {
  if (input.length() == 2) {
    if (input[0] == '-') {
      return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}

bool is_it_valid_typing_for_second_element(string input) {
  if (input.length() == 1) {
    return true;
  }
  else {
    return false;
  }
}

char one_letter_from_string(string input) {
  if (is_it_valid_typing_for_first_element(input) == true) {
    return input[1];
  }
  else {
    return '!';
  }
}

bool is_string_only_number(string input) {
  int num_checker = 0;
  for (int i = 0; i < input.length(); i++) {
   if ((int)input[i] <= 57 && (int)input[i] >= 48) {
     num_checker++;
   }
  }
  if (num_checker == input.length()) {
    return true;
  }
  else {
    return false;
  }
}

int int_from_string(string input) {
  int temp = 0;
  int digit = 1;
  for (int i = 0; i < input.length(); i++) {
    digit *= 10;
  }
  digit = digit / 10;
  for (int i = 0; i < input.length(); i++) {
    temp += ((int)input[i] - 48) * digit;
    digit *= 0.1;
  }
  return temp;
}

string string_from_int(int input) {
  stringstream ss;
  ss << input;
  return ss.str();
}

bool is_command_valid(char input, string commands) {
  for (int i = 0; i < commands.length(); i ++) {
    if (input == commands[i]) {
      return true;
    }
  }
  return false;
}

void print_from_string(string input, char checked) {
  istringstream iss(input);
  string line;
  int i = 1;
  while (getline(iss, line)) {
    cout << i++ << " - [" << checked << "] " << line << endl;
  }
}

#endif // FUNCTIONTOOLS_H
