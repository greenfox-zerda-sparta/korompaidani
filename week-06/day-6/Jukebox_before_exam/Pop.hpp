#ifndef POP_H
#define POP_H

#include "Song.hpp"
#include <string>

class Pop : public Song {
  public:
    Pop(std::string, std::string);
    Pop(int);
};

#endif // POP_H
