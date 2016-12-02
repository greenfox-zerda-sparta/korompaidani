#include <iostream>
#include "Rock.hpp"

using namespace std;

int main()
{
    Rock r1 ("Gyongyhaju lany", "Omega");
    cout << r1.get_artist() << "|";
    cout << r1.get_title() << "|";
    cout << r1.get_genre() << "|";
    cout << r1.add_rating(4) << "|";
    cout << r1.get_last_rating() << "|";

    return 0;
}
