#include <iostream>
#include "Song.hpp"

using namespace std;

Song::Song(string in_title, string in_artist) {
  this->title = in_title;
  this->artist = in_artist;
  this->rating = 0;
  this->rating_counter = 0;
};

bool Song::add_rate(int in_rate) {
  if (in_rate >= 1 && in_rate <= 5) {
    rating += in_rate;
    rating_counter++;
    return true;
  }
  else {
    return false;
  }
};

void Song::get_info() {
  cout << "The |" << title << "| from |" << artist << "| has |" << this->get_aver_rating() << "|\n";
};

float Song::get_aver_rating() {
  if (rating_counter != 0) {
    return float(rating) / rating_counter;
  }
  else {
    return 0;
  }
};
