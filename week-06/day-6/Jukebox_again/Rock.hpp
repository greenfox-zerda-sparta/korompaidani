#ifndef ROCK_H
#define ROCK_H

#include <string>
#include "Song.hpp"

class Rock : public Song {
  private:
  public:
    Rock(std::string, std::string);
    bool add_rating(unsigned short int);
  };

#endif // ROCK_H
