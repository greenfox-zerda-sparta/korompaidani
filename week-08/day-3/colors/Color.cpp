#include "Color.hpp"

std::string Color::int_to_hex(unsigned char num) {
  std::stringstream stream;
  stream << std::hex << num;
  std::string result(stream.str());
  return result;
}

int Color::hex_to_int(std::string hex) {
  unsigned char num;
  std::stringstream ss;
  ss << std::hex << hex;
  ss >> num;
  return num;
}

std::string Color::split_hex_string(std::string input_hex, char channel) {
  if (channel == 'R') {

  }
  else if (channel == 'G') {

  }
  else if (channel == 'B') {

  }
  return "F";
}

Color::Color() {
  this->red = 0;
  this->green = 0;
  this->blue = 0;
}

Color::Color(unsigned char red, unsigned char green, unsigned char blue) {
  this->red = red;
  this->green = green;
  this->blue = blue;
}

Color::Color(std::string hex_color) {
  
}

Color::~Color() {
}

unsigned char* Color::get_red() {
  return &red;
}

unsigned char* Color::get_green() {
  return &green;
}

unsigned char* Color::get_blue() {
  return &blue;
}
