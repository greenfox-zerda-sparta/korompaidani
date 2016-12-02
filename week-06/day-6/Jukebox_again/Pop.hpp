#ifndef POP_H
#define POP_H

#include "Song.hpp"

class Pop : public Song {
  public:
    Pop(std::string, std::string);
    bool add_rating(unsigned short int);
};

#endif // POP_H
