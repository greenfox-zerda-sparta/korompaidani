#ifndef JUKEBOX_H
#define JUKEBOX_H

#include <vector>
#include "Song.hpp"

class Jukebox {
  private:
    std::vector<Song*> songs;
  public:
    Jukebox();
    void add_song(Song);
    float get_artist_rating(std::string);
};

#endif // JUKEBOX_H
