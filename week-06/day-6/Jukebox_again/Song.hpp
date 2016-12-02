#ifndef SONG_H
#define SONG_H

#include <string>

class Song {
  protected:
    std::string title;
    std::string artist;
    std::string genre;
    unsigned short int rating;
  public:
    Song(std::string, std::string);
};

#endif // SONG_H
