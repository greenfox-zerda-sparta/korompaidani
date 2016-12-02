#ifndef ROCK_H
#define ROCK_H

#include "Song.hpp"

class Rock : public Song {
  public:
    Rock(std::string, std::string);
    bool add_rating(unsigned short int);
};

#endif // ROCK_H
