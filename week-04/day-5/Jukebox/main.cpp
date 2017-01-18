#include <iostream>
#include "Song.h"

using namespace std;

int main()
{
  Song s1("Mix Sensation Podcast 92", "Stereopalma");
  cout << s1.add_rating(1) << endl;
  cout << s1.add_rating(3) << endl;
  s1.get_rate_n_rate_counter();
  cout << "This is the average: " << s1.get_average_rating();
  return 0;
}
