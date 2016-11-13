#ifndef SONG_H
#define SONG_H

#include <iostream>

using namespace std;

class Song {
protected:
  string title;
  string artist;
  int rating;
  unsigned short int rating_counter;
  string genre;
public:
  Song(string in_title, string in_artist);
  virtual bool add_rate(int in_rate);
  void get_info();
  float get_aver_rating();
};

#endif // SONG_H
