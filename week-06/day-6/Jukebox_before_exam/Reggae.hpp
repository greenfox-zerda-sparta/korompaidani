#ifndef REGGAE_H
#define REGGAE_H

#include "Song.hpp"
#include <string>

class Reggae : public Song {
  public:
    Reggae(std::string, std::string);
};

#endif // REGGAE_H