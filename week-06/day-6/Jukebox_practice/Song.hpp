#ifndef SONG_H
#define SONG_H

#include <string>
#include <vector>

class Song {
  private:
    std::string artist;
    std::string title;
    std::vector<int> rating;
    int rating_counter;
  protected:
    std::string genre;
    int rating_frame_bottom;
    int rating_frame_top;
  public:
    Song(std::string, std::string);
    std::string get_artist();
    std::string get_title();
    std::string get_genre();
    int get_rating_counter();
    float get_average_rating();
    bool rate(int);
    int get_sum_of_rating();
};

#endif // SONG_H
