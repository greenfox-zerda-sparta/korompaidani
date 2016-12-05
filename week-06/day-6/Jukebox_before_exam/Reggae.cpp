#include "Reggae.hpp"

Reggae::Reggae(std::string in_artist, std::string in_title) : Song(in_artist, in_title) {
  rating_frame_top = 5;
  genre = "Reggae";
}
