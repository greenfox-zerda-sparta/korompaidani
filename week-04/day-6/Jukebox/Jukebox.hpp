#ifndef JUKEBOX_H
#define JUKEBOX_H

#include "Song.hpp"
#include "Rock.hpp"
#include "Pop.hpp"
#include "Reggae.hpp"
#include <iostream>

using namespace std;

class Jukebox {
private:
  Song** songs;
  int song_counter;
public:
  Jukebox();
  void add_song(Song& song);
  void add_rate(Song& song, int in_rating);
  void show_box_storage();
  void get_artist_rating(string in_artist);
  void get_genre_rating(string in_genre);
  void get_top_rated_title();
  void get_top_rated_genre();
};

#endif // JUKEBOX_H
