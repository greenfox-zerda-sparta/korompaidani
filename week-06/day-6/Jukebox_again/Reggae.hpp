#ifndef REGGAE_H
#define REGGAE_H
#include "Song.hpp"

class Reggae : public Song {
  public:
    Reggae(std::string, std::string);
    bool add_rating(unsigned short int);
};

#endif // REGGAE_H
