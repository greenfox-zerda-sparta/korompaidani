#include "Reggae.hpp"

#include "Song.hpp"
#include <iostream>

using namespace std;

Reggae::Reggae(string  in_title, string in_artist) : Song(in_title, in_artist) {
  this->genre = "Reggae";
};

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
