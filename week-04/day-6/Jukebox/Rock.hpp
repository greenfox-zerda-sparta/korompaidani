#ifndef ROCK_H
#define ROCK_H

#include "Song.hpp"
#include <iostream>

using namespace std;

class Rock : public Song {
public:
  Rock(string in_title, string in_artist);
  virtual bool add_rate(int in_rate);
};

#endif // ROCK_H

