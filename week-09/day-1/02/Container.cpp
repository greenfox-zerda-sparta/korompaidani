#include "stdafx.h"
#include "Container.hpp"

Container::Container() {
}

Container::~Container() {
}

int Container::get_sum_of_your_vector(std::vector<int>& in_vec) {
  int temp = 0;
  in_vec.push_back(4);
  for (int i = 0; i < in_vec.size(); i++) {
    temp += in_vec[i];
  }
  return temp;
}
