#include "Rock.hpp"

Rock::Rock(std::string in_artist, std::string in_title) : Song(in_artist, in_title) {
  rating_frame_bottom = 1;
  genre = "Rock";
}
