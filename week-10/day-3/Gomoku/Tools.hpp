#pragma once
#include <string>
#include <sstream>
#include <utility>

using std::string;
using std::stringstream;
using std::pair;

string m_int_to_string(int);
pair<string, string> split_at_comma(string);
pair<int, int> m_string_to_int_pair(string);

string m_int_to_string(int num) {
  stringstream stream;
  stream << num;
  string result(stream.str());
  return result;
}

pair<string, string> split_at_comma(string input) {
  pair<string, string> temp;
  int index = 0;
  for (int i = 0; input.length(); i++) {
    if (input[i] != ',') {
      temp.first += input[i];
      index++;
    }
    else {
      break;
    }
  }
  for (int i = index + 1; i < input.length(); i++) {
    temp.second += input[i];
  }  
  return temp;
}

pair<int, int> m_string_to_int_pair(string input) {
  pair<string, string> str_pair = split_at_comma(input);
  pair<int, int> num_pair;
  stringstream sf;
  stringstream ss;
  sf << str_pair.first;
  sf >> num_pair.first;
  ss << str_pair.second;
  ss >> num_pair.second;
  return num_pair;
}