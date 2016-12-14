#pragma once

#include <cstdint>
#include <iomanip>
#include <sstream>

class Color {
private:
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  std::string int_to_hex(int);
  int hex_to_int(std::string);
public:
  Color();
  ~Color();
  virtual uint8_t get_red();
  virtual uint8_t get_green();
  virtual uint8_t get_blue();
};

