#include <iostream>
#ifndef SONG_H
#define SONG_H


class Song {
  public:
    Song();
    Song(std::string intitle, std::string inartist);
    bool add_rating(short unsigned int inrate);
    double get_average_rating();
    void get_rate_n_rate_counter();
  private:
    std::string title;
    std::string artist;
    short unsigned int rate;
    int rate_counter = 0;
};

#endif // SONG_H
