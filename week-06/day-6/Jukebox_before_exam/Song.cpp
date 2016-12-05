#include "Song.hpp"

Song::Song(std::string in_artist, std::string in_title) {
  this->artist = in_artist;
  this->title = in_title;
  this->genre = "";
  this->rating.resize(0);
  this->rating_frame_bottom = 0;
  this->rating_frame_top = 6;
  this->rating_sum = 0;
  this->rating_counter = 0;
}

bool Song::rate(int in_rate) {
  bool temp_answer;
  if (in_rate > rating_frame_bottom && in_rate < rating_frame_top) {
    this->rating.push_back(in_rate);
    this->rating_counter = rating.size();
    this->rating_sum += (float)in_rate;
    temp_answer = true;
  }
  else {
    temp_answer = false;
  }
  return temp_answer;
}

float Song::get_average_of_rating() {
  float temp_average = 0;
  for (int i = 0; i < this->rating.size(); i++) {
    temp_average += rating[i];
  }
  return temp_average / this->rating.size();
}

float Song::get_rating_sum() {
  return this->rating_sum;
}

int Song::get_rating_counter() {
  return this->rating_counter;
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
