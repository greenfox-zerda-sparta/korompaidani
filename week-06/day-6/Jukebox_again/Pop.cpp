#include "Pop.hpp"

Pop::Pop(std::string in_title, std::string in_artist) : Song(in_title, in_artist) {
  genre = "Reggae";
}

bool Pop::add_rating(unsigned short int in_rate) {
  if (in_rate > 5 || in_rate < 1) {
    return false;
  }
  else {
    ratings.push_back(in_rate);
    return true;
  }
}
