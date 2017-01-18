#include "stdafx.h"
#include "Apple.hpp"


Apple::Apple() {
  this->app = "apple";
}


Apple::~Apple() {
}

std::string Apple::get_app() {
  return this->app;
}
