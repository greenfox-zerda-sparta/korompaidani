#include "Rock.hpp"

Rock::Rock(std::string in_title, std::string in_artist) : Song(in_title, in_artist) {
  genre = "Rock";
}

bool Rock::add_rating(unsigned short int in_rate) {
  if (in_rate > 5 || in_rate < 2) {
    return false;
  }
  else {
    ratings.push_back(in_rate);
    return true;
  }
}
