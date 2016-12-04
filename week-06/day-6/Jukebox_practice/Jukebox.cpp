#include "Jukebox.hpp"

Jukebox::Jukebox() {
  storage.resize(0, NULL);
}

void Jukebox::add_song(Song& in_song) {
  storage.push_back(&in_song);
}

bool Jukebox::rate_song(std::string in_artist, std::string in_title, int in_rate) {
  for (int i = 0; i < storage.size(); i++) {
    if (in_artist == storage[i]->get_artist()) {
      if (in_title == storage[i]->get_title()) {
        storage[i]->rate(in_rate);
      }
    }
  }
  return true;
}

float Jukebox::get_artist_rating(std::string find_artist) {
  float sum_of_rating_temp = 0;
  int sum_of_rating_counter = 0;
  for (int i = 0; i < storage.size(); i++) {
    if (find_artist == storage[i]->get_artist()) {
      sum_of_rating_temp += (float)storage[i]->get_sum_of_rating();
      sum_of_rating_counter += storage[i]->get_rating_counter();
    }
  }
  return sum_of_rating_temp / sum_of_rating_counter;
}

float Jukebox::get_genre_rating(std::string find_genre) {
  float sum_of_rating_temp = 0;
  int sum_of_rating_counter = 0;
  for (int i = 0; i < storage.size(); i++) {
    if (find_genre == storage[i]->get_genre()) {
      sum_of_rating_temp += (float)storage[i]->get_sum_of_rating();
      sum_of_rating_counter += storage[i]->get_rating_counter();
    }
  }
  return sum_of_rating_temp / sum_of_rating_counter;
}
