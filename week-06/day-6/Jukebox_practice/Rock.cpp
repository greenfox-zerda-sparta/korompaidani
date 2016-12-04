#include "Rock.hpp"

Rock::Rock(std::string in_artist, std::string in_title) : Song(in_artist, in_title) {
  genre = "Rock";
  rating_frame_bottom = 2;
}
