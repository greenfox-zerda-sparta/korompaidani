#ifndef SONG_H
#define SONG_H

#include <string>
#include <vector>

class Song {
  private:
    std::string artist;
    std::string title;
    std::vector<int> rating;
    float rating_sum;
    int rating_counter;
  protected:
    std::string genre;
    unsigned short int rating_frame_bottom;
    unsigned short int rating_frame_top;
  public:
    Song(std::string, std::string);
    bool rate(int);
    float get_average_of_rating();
    float get_rating_sum();
    int get_rating_counter();
    std::string get_artist();
    std::string get_title();
    std::string get_genre();

};

#endif // SONG_H
