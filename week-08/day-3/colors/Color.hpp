#pragma once

#include <cstdint>
#include <iomanip>
#include <sstream>

class Color {
private:
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  std::string int_to_hex(unsigned char);
  int hex_to_int(std::string);
  std::string split_hex_string(std::string, char);
public:
  Color();
  Color(unsigned char, unsigned char, unsigned char);
  Color(std::string);
  ~Color();
  virtual unsigned char* get_red();
  virtual unsigned char* get_green();
  virtual unsigned char* get_blue();
};

