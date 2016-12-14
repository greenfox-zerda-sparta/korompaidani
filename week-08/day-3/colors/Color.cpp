#include "Color.hpp"

std::string Color::int_to_hex(int num) {
  std::stringstream stream;
  stream << std::hex << num;
  std::string result(stream.str());
  return result;
}

int Color::hex_to_int(std::string hex) {
  int num;
  std::stringstream ss;
  ss << std::hex << hex;
  ss >> num;
  return num;
}

Color::Color() {
  this->red = 0;
  this->green = 255;
  this->blue = 0;
}

Color::~Color() {
}

uint8_t Color::get_red() {
  return this->red;
}

uint8_t Color::get_green() {
  return this->green;
}

uint8_t Color::get_blue() {
  return this->blue;
}
