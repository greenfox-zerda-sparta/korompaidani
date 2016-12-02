#include <iostream>
#include "Rock.hpp"
#include "Pop.hpp"
#include "Reggae.hpp"
#include "Jukebox.hpp"

using namespace std;

int main()
{
    Rock r1 ("Gyongyhaju lany", "Omega");
    cout << r1.get_artist() << "|";
    cout << r1.get_title() << "|";
    cout << r1.get_genre() << "|";
    cout << r1.add_rating(4) << "|";
    cout << r1.add_rating(3) << "|";
    cout << r1.get_last_rating() << "|";
    cout << r1.get_rating_average() << "|";

    Rock r2 ("Petroleum lampa", "Omega");
    r2.add_rating(5);

    Jukebox j1;
    j1.add_song(r1);
    j1.add_song(r2);
    cout << endl << endl << j1.get_artist_rating("Omega");

    return 0;
}
