#include "Rock.hpp"
#include "Song.hpp"
#include <iostream>

using namespace std;

Rock::Rock(string in_title, string in_artist) {
  this->title = in_title;
  this->artist = in_artist;
  this->rating = 0;
  this->rating_counter = 0;
  this->genre = "Rock";
};

bool Rock::add_rate(int in_rate) {
  if (in_rate >= 2 && in_rate <= 5) {
    rating += in_rate;
    rating_counter++;
    return true;
  }
  else {
    return false;
  }
};
