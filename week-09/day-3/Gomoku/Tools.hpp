#pragma once
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

string int_to_string(int num) {
  stringstream stream;
  stream << num;
  string result(stream.str());
  return result;
}
