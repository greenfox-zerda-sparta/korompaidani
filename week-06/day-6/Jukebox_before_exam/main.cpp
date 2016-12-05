#include <iostream>

#include "Rock.hpp"
#include "Reggae.hpp"
#include "Pop.hpp"
#include "Jukebox.hpp"

using namespace std;

int main() {
  Rock r1("Omega", "Gyongyhaju_lany");
  Rock r2("Omega", "Petroleum_lampa");

  Jukebox j1;

  j1.add_song(r1);
  j1.add_song(r2);
  cout << j1.rate_song("Omega", "Gyongyhaju_lany", 4) << endl;
  cout << j1.rate_song("Omega", "Gyongyhaju_lany", 5) << endl;
  cout << j1.rate_song("Omega", "Petroleum_lampa", 4) << endl;
  cout << j1.rate_song("Omega", "Petroleum_lampa", 2) << endl;

  cout << endl;

  cout << j1.get_title_rating("Gyongyhaju_lany") << endl;
  cout << j1.get_title_rating("Petroleum_lampa") << endl;
  cout << j1.get_artist_rating("Omega") << endl;
  cout << j1.get_top_ratid_title() << endl;


  return 0;
}
