#include "Reggae.hpp"

Reggae::Reggae(std::string in_artist, std::string in_title) : Song(in_artist, in_title) {
  genre = "Reggae";
  rating_frame_top = 4;
}
