#include "Reggae.hpp"

Reggae::Reggae(std::string in_title, std::string in_artist) : Song(in_title, in_artist) {
  genre = "Reggae";
}

bool Reggae::add_rating(unsigned short int in_rate) {
  if (in_rate > 4 || in_rate < 1) {
    return false;
  }
  else {
    ratings.push_back(in_rate);
    return true;
  }
}
