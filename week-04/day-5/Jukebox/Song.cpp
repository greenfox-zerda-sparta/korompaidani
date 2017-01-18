#include <iostream>
#include "Song.h"

Song::Song(std::string intitle, std::string inartist) {
  title = intitle;
  artist = inartist;
  rate = 0;
};

Song::Song() {
};

bool Song::add_rating(short unsigned int inrate) {
  if (inrate >= 1 && inrate <= 5) {
    rate += inrate;
    rate_counter++;
    return true;
  }
  else {
    return false;
  }
};

double Song::get_average_rating() {
  return (double)rate / rate_counter;
};

void Song::get_rate_n_rate_counter() {
  std::cout << "This is actual rate: " << rate << std::endl;
  std::cout << "This is actual rate_ counter: " << rate_counter << std::endl;
};
