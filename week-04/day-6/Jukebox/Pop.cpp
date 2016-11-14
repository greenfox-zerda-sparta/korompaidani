#include "Pop.hpp"
#include "Song.hpp"

Pop::Pop(string in_title, string in_artist) : Song(in_title, in_artist) {
  this->genre = "Pop";
};
