#include "Reggae.hpp"

#include "Song.hpp"
#include <iostream>

using namespace std;

bool Reggae::add_rate(int in_rate) {
  if (in_rate >= 1 && in_rate <= 4) {
    rating += in_rate;
    rating_counter++;
    return true;
  }
  else {
    return false;
  }
};
