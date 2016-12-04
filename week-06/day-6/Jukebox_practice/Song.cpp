#include "Song.hpp"

Song::Song(std::string in_artist, std::string in_title) {
  this->artist = in_artist;
  this->title = in_title;
  this->genre = "";
  this->rating_counter = 0;
  this->rating.resize(0, 0);
  this->rating_frame_bottom = 1;
  this->rating_frame_top = 5;
}

std::string Song::get_artist() {
  return this->artist;
}

std::string Song::get_title() {
  return this->title;
}

std::string Song::get_genre() {
  return this->genre;
}

int Song::get_rating_counter() {
  return this->rating_counter;
}

float Song::get_average_rating() {
  float rat_temp = 0;
  for (int i = 0; i < rating.size(); i++) {
    rat_temp += rating[i];
  }
  return rat_temp / rating.size();
}

bool Song::rate(int user_rating) {
  if (user_rating < rating_frame_bottom || user_rating > rating_frame_top) {
    return false;
  }
  else {
    this->rating_counter++;
    this->rating.push_back(user_rating);
    return true;
  }
}

int Song::get_sum_of_rating() {
  int ratings_sum = 0;
  for (int i = 0; i < rating.size(); i++) {
    ratings_sum += rating[i];
  }
  return ratings_sum;
}
