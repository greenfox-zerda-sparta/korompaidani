#include <iostream>
#include "Song.hpp"
#include "Rock.hpp"

using namespace std;

class Jukebox {
private:
  Song** songs;
  int song_counter;
public:
  Jukebox();
  void add_song(Song& song);
};

Jukebox::Jukebox() {
  songs = NULL;
  song_counter = 0;
};

void Jukebox::add_song(Song& song) {
  Song** temp = new Song*[song_counter + 1];
  if (songs!= NULL) {
    for (int i = 0; i < song_counter; i++) {
      temp[i] = songs[i];
    }
  }
  temp[song_counter] = &song;
  delete[] songs;
  songs = temp;
  ++song_counter;
};

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

  j1.add_song(s1);

  Rock s2("Yellow submarine","The Beatles");

  return 0;
}
