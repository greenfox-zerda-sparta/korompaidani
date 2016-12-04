#ifndef ROCK_H
#define ROCK_H

#include <string>
#include "Song.hpp"

class Rock : public Song {
  public:
    Rock(std::string, std::string);
};

#endif // ROCK_H
