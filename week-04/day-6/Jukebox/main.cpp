#include <iostream>
#include "Song.hpp"
#include "Rock.hpp"
#include "Jukebox.hpp"

using namespace std;

int main()
{
  Song s1("Yellow submarine","The Beatles");
  s1.get_info();
  s1.add_rate(5);
  s1.get_info();
  s1.add_rate(2);
  s1.get_info();
  cout << "Average is: " << s1.get_aver_rating() << endl;

  Jukebox j1;



  Rock s2("Mix Sensation Podcast","Stereopalma");
  s2.add_rate(4);
  s2.add_rate(2);
  s2.get_info();

  j1.add_song(s2);
  return 0;
}
