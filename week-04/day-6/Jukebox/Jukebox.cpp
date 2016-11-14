#include "Jukebox.hpp"
#include "Song.hpp"
#include "Rock.hpp"
#include "Pop.hpp"
#include "Reggae.hpp"
#include <iostream>

using namespace std;

Jukebox::Jukebox() {
  songs = NULL;
  song_counter = 0;
};

void Jukebox::add_song(Song& song) {
  Song** temp = new Song*[song_counter + 1];
  if (songs!= NULL) {
    for (int i = 0; i < song_counter; i++) {
      temp[i] = songs[i];
    }
  }
  temp[song_counter] = &song;
  delete[] songs;
  songs = temp;
  ++song_counter;
};
