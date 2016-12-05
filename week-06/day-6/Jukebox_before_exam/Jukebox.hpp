#ifndef JUKEBOX_H
#define JUKEBOX_H

#include "Song.hpp"
#include <string>
#include <vector>
#include <iostream>

class Jukebox {
  private:
    std::vector<Song*> storage;
  public:
    Jukebox();
    void add_song(Song&);
    bool rate_song(std::string, std::string, int);
    float get_artist_rating(std::string);
    float get_title_rating(std::string);
    float get_genre_rating(std::string);
    std::string get_top_ratid_title();
};

#endif // JUKEBOX_H
