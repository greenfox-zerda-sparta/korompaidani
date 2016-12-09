#include "score.hpp"

score::score() {
  enemy_death_counter = 0;
  treasure_catch_counter = 0;
  this->score_content = "";
}

score::~score() {
}

std::string score::int_to_string(int in_int) {
  std::ostringstream ss;
  ss << in_int;
  return ss.str();
}

std::string score::get_score_content() {
  score_content += "========Scores========\n";
  score_content += "enemy death score: ";
  score_content += int_to_string(this->enemy_death_counter);
  score_content += "\ntreasure score: ";
  score_content += int_to_string(this->treasure_catch_counter);
  score_content += "\n======================\n";
  return score_content;
}

  void score::fill_score(int enemy_data, int treasure_data) {
    enemy_death_counter = enemy_data;
    treasure_catch_counter = treasure_data;
}
