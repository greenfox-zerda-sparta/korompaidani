#include <iostream>
#include "Song.hpp"
#include "Rock.hpp"
#include "Jukebox.hpp"

using namespace std;

int main()
{
  Jukebox j1;
  Pop Beatles("Yellow submarine","The Beatles");
  Rock Stereopalma("Mix Sensation Podcast","Stereopalma");
  Reggae Bob("Sunshine Reggae", "Bob Marley");

  j1.add_song(Beatles);
  j1.add_song(Stereopalma);
  j1.add_song(Bob);

  j1.add_rate(Beatles,5);
  j1.add_rate(Stereopalma,3);
  j1.add_rate(Beatles,2);
  j1.add_rate(Bob,4);

  j1.show_box_storage();

  j1.get_artist_rating("Bob Marley");

  j1.get_genre_rating("Rock");
  j1.get_top_rated_title();

  return 0;

}
