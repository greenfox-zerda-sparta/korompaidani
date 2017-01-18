#include "Color.hpp"

std::string Color::int_to_hex(unsigned char num) {
  std::stringstream stream;
  stream << std::hex << num;
  std::string result(stream.str());
  return result;
}

int Color::hex_to_int(std::string in_hex) {
  int num;
  std::stringstream ss;
  ss << std::hex << in_hex;
  ss >> num;
  return num;
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
  this->c_red = hex_color[1];
  this->c_red += hex_color[2];
  this->c_green = hex_color[3];
  this->c_green += hex_color[4];
  this->c_blue = hex_color[5];
  this->c_blue += hex_color[6];
  web_color_to_rgb();
}

Color::~Color() {
}

void Color::web_color_to_rgb() {
  this->red = hex_to_int(c_red);
  this->green = hex_to_int(c_green);
  this->blue = hex_to_int(c_blue);
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

void Color::make_negative() {
  this->red = 255 - this->red;
  this->green = 255 - this->green;
  this->blue = 255 - this->blue;
}

void Color::blend(Color& other_color) {
  this->red = (this->red + *other_color.get_red()) / 2;
  this->green = (this->green + *other_color.get_green()) / 2;
  this->blue = (this->blue + *other_color.get_blue()) / 2;
}

void Color::lighten_10() {
  if (this->red + 255 / 10 > 0 && this->red + 255 / 10 < 26) {
    this->red += 255 / 10;
  }
  else {
    this->red = 255;
  }
  if (this->green + 255 / 10 > 0 && this->green + 255 / 10 < 26) {
    this->green += 255 / 10;
  }
  else {
    this->green = 255;
  }
  if (this->blue + 255 / 10 > 0 && this->blue + 255 / 10 < 26) {
    this->blue += 255 / 10;
  }
  else {
    this->blue = 255;
  }
}
