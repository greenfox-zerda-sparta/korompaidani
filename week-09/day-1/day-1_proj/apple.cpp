#include "apple.hpp"

apple::apple() {
  this->apple_ = "apple";
}

apple::~apple() {
}

std::string apple::get_apple() {
  return apple_;
}
