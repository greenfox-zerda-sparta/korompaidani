#include "Song.hpp"

Song::Song(std::string in_title, std::string in_artist) {
  ratings.resize(0, 0);
  title = in_title;
  artist = in_artist;
}

std::string Song::get_title() {
  return title;
};

std::string Song::get_artist() {
  return artist;
};

std::string Song::get_genre() {
  return genre;
};

int Song::get_last_rating() {
  if (ratings.size() > 0) {
    return ratings.back();
  }
  else {
    return 0;
  }
};

float Song::get_rating_average() {
  float temp = 0;
  for (int i = 0; i < ratings.size(); i++) {
    temp += (float)ratings[i];
  }
  return temp / ratings.size();
};
