#ifndef SONG_H
#define SONG_H

#include <vector>
#include <string>

class Song {
  protected:
    std::string title;
    std::string artist;
    std::string genre;
    std::vector<int> ratings;
  public:
    Song(std::string, std::string);
    std::string get_title();
    std::string get_artist();
    std::string get_genre();
    int get_last_rating();
};

#endif // SONG_H
