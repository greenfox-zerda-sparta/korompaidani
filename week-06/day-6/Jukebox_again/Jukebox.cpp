#include "Jukebox.hpp"

Jukebox::Jukebox() {
  songs.resize(0, NULL);
}

void Jukebox::add_song(Song in_song) {
  songs.push_back(&in_song);
}

float Jukebox::get_artist_rating(std::string in_artist) {
  float temp_aver = 0;
  int aver_counter = 0;
  for (int i = 0; i < songs.size(); i++) {
    if (songs[i]->get_artist() == in_artist) {
      aver_counter++;
      temp_aver += songs[i]->get_rating_average();
    }
  }
  return temp_aver / aver_counter;
}

