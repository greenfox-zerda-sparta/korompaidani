#ifndef REGGAE_H
#define REGGAE_H

#include "Song.hpp"
#include <iostream>

using namespace std;

class Reggae : public Song {
public:
  Reggae(string  in_title, string in_artist);
  virtual bool add_rate(int in_rate);
};

#endif // REGGAE_H
