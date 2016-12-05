#ifndef ROCK_H
#define ROCK_H

#include "Song.hpp"
#include <string>

class Rock : public Song {
  public:
    Rock(std::string, std::string);
};

#endif // ROCK_H
