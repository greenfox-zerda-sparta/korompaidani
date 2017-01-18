#pragma once

#include <iostream>
#include <cstdint>
#include <iomanip>
#include <sstream>

class Color {
private:
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  std::string c_red;
  std::string c_green;
  std::string c_blue;
  std::string int_to_hex(unsigned char);
  int hex_to_int(std::string);
public:
  Color();
  Color(unsigned char, unsigned char, unsigned char);
  Color(std::string);
  ~Color();
  void web_color_to_rgb();
  virtual unsigned char* get_red();
  virtual unsigned char* get_green();
  virtual unsigned char* get_blue();
  void make_negative();
  void blend(Color&);
  void lighten_10();
};