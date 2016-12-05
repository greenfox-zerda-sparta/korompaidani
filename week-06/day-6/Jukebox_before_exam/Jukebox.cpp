#include "Jukebox.hpp"

Jukebox::Jukebox() {
  storage.resize(0, NULL);
}

void Jukebox::add_song(Song& in_song) {
  storage.push_back(&in_song);
}

bool Jukebox::rate_song(std::string in_artist, std::string in_title, int in_rate) {
  bool temp_answer = false;
  for (int i = 0; i < storage.size(); i++) {
    if (in_artist != storage[i]->get_artist()) {
    }
    else {
      if (in_title != storage[i]->get_title()) {
      }
      else {
        temp_answer = true;
        storage[i]->rate(in_rate);
      }
    }
  }
  return temp_answer;
}

float Jukebox::get_artist_rating(std::string in_artist) {
  float temp_rating_sum = 0;
  int temp_rating_counter = 0;
  for (int i = 0; i < storage.size(); i++) {
    if (in_artist == storage[i]->get_artist()) {
      temp_rating_sum += storage[i]->get_rating_sum();
      temp_rating_counter += storage[i]->get_rating_counter();
    }
  }
  return temp_rating_sum / temp_rating_counter;
}

float Jukebox::get_title_rating(std::string in_title) {
  float temp_rating_sum = 0;
  int temp_rating_counter = 0;
  for (int i = 0; i < storage.size(); i++) {
    if (in_title == storage[i]->get_title()) {
      temp_rating_sum += storage[i]->get_rating_sum();
      temp_rating_counter += storage[i]->get_rating_counter();
    }
  }
  return temp_rating_sum / temp_rating_counter;
}

float Jukebox::get_genre_rating(std::string in_genre) {
  float temp_rating_sum = 0;
  int temp_rating_counter = 0;
  for (int i = 0; i < storage.size(); i++) {
    if (in_genre == storage[i]->get_genre()) {
      temp_rating_sum += storage[i]->get_rating_sum();
      temp_rating_counter += storage[i]->get_rating_counter();
    }
  }
  return temp_rating_sum / temp_rating_counter;
}

std::string Jukebox::get_top_ratid_title() {
  int temp_index = 0;
  if (storage[0]->get_average_of_rating() != NULL) {
    float temp_top_rating = storage[0]->get_average_of_rating();
    for (int i = 0; i < storage.size(); i++) {
      if (temp_top_rating < storage[i]->get_average_of_rating()) {
        temp_top_rating = storage[i]->get_average_of_rating();
        temp_index = i;
      }
    }
  }
  return storage[temp_index]->get_title();
};
