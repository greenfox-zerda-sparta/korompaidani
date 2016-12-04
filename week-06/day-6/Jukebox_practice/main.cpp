#include <iostream>
#include "Rock.hpp"
#include "Reggae.hpp"
#include "Pop.hpp"
#include "Jukebox.hpp"

using namespace std;

int main() {
    Rock r1("Omega", "Gyongyhaju lany");
    cout << r1.get_artist() << "|";
    cout << r1.get_title() << "|";
    cout << r1.get_genre() << "|";

    //cout << r1.rate(9) << "<- r |";
    //cout << r1.rate(1) << "<- r |";
    //cout << r1.rate(5) << "<- r |";
    //cout << r1.rate(4) << "<- r |";

    //cout << r1.get_average_rating() << "|";

    cout << endl;

    Rock r2("Omega", "Title");
    Pop p1("Justin Bieber", "Who I am?");

    Jukebox j1;
    j1.add_song(r1);
    j1.add_song(r2);
    j1.add_song(p1);

    cout << p1.get_genre() << endl;

    j1.rate_song("Omega", "Title", 5);
    j1.rate_song("Omega", "Gyongyhaju lany", 2);
    j1.rate_song("Justin Bieber", "Who I am?", 1);
    j1.rate_song("Justin Bieber", "Who I am?", 3);

    cout << "Artist rating = " << j1.get_artist_rating("Omega") << endl;
    cout << "Gengre rating = " << j1.get_genre_rating("Pop") << endl;

    return 0;
}
