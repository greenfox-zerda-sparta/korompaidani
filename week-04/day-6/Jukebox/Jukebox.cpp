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

void  Jukebox::add_rate(Song& song, int in_rating) {
  song.add_rate(in_rating);
};

void Jukebox::show_box_storage() {
  for (int i = 0; i < this->song_counter; i++) {
    cout << (*songs)[i].get_info() << endl;
  }
  cout << endl;
};

void Jukebox::get_artist_rating(string in_artist) {
  bool checker = false;
  int index;
  for (int i = 0; i < this->song_counter; i++) {
    if (in_artist == (*songs)[i].get_artist()) {
      checker = true;
      index = i;
      break;
    }
  }
  if (checker == true) {
    cout << "|" << in_artist << "'s| rating average is: |" << (*songs)[index].get_aver_rating() << "| " << endl;
  }
  else {
    cout << "Your Jukebox doesn't contain \"|" << in_artist << "|\" artist." << endl;
  }
};

void Jukebox::get_genre_rating(string in_genre) {
  float avers_aver = 0;
  int aver_counter = 0;
  for (int i = 0; i < this->song_counter; i++) {
    if (in_genre == ((*songs)[i].get_genre())) {
      avers_aver += (*songs)[i].get_aver_rating();
      aver_counter++;
    }
  }
  if (aver_counter > 0) {
    cout << "|" << in_genre << "| average in your Jukebox is: |" << avers_aver / aver_counter << "|" << endl;
  }
  else {
    cout << "Your Jukebox doesn't contain \"|" << in_genre << "|\" genre." << endl;
  }
};

void Jukebox::get_top_rated_title() {
  float top_aver = (*songs)[0].get_aver_rating();
  int top_rated_index = 0;
  for (int i = 0; i < this->song_counter; i++) {
    if (((*songs)[i].get_aver_rating()) > top_aver) {
      top_aver = (*songs)[i].get_aver_rating();
      top_rated_index = i;
    }
  }
  cout << "The title of the top rated song is: |" << (*songs)[top_rated_index].get_title() << "|" << endl;
};

void Jukebox::get_top_rated_genre() {

};
