#ifndef JUKEBOX_H
#define JUKEBOX_H

#include <string>
#include <vector>
#include "Song.hpp"

class Jukebox {
  private:
    std::vector<Song*> storage;
  public:
    Jukebox();
    void add_song(Song&);
    bool rate_song(std::string, std::string, int);
    float get_artist_rating(std::string);
    float get_genre_rating(std::string);
};

#endif // JUKEBOX_H
