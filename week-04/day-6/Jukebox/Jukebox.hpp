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
};

#endif // JUKEBOX_H
