#include <iostream>
#include "Song.hpp"
#include "Util.hpp"

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

string Song::get_info() {
  return "The |" + this->title + "| from |" + this->artist + "| has |" + float_to_string(this->get_aver_rating()) + "|";
};

float Song::get_aver_rating() {
  if (rating_counter != 0) {
    return float(rating) / rating_counter;
  }
  else {
    return 0;
  }
};

string Song::get_genre() {
  return genre;
};

string Song::get_artist() {
  return artist;
};

string Song::get_title() {
  return title;
};
