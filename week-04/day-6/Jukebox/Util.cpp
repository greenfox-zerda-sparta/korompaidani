#include "Util.hpp"
#include <sstream>
#include <string>

std::string float_to_string(float input) {
  std::stringstream ss;
  ss << input;
  return ss.str();
}
