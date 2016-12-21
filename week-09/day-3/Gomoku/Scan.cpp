#include "Scan.hpp"

Scan::Scan() {
}

bool Scan::horizontal(Map& map) {
  int counter = 0;
  for (int i = 0; i < map.get_map().size(); i++) {
    for (int j = 0; j < map.get_map()[i].size(); j++) {
      if (map.get_map()[i][j] != 0) {
        counter++;
        if (counter == 5) {
          this->win_case.first = 'h';
          this->win_case.second = j;
          this->win_player_num = map.get_map()[i][j];
          return true;
        }
      }
      else {
        counter = 0;
      }
    }
  }
  return false;
}

bool Scan::vertical(Map& map) {
  int counter = 0;
  int lines;
  for (int j = 0; j < map.get_map()[2].size(); j++) {
    lines = 2 + 1;
    if (map.get_map()[2][j] != 0) {
      counter++;
      while (19 - 2 - lines > 4) {
        if (map.get_map()[lines][j] != 0) {
          counter++;
          std::cout << "the counter is: " << counter << std::endl;
        }
        lines++;
      }
    }
  }
  return false;
}

std::pair<char, int> Scan::get_win_case() {
  return this->win_case;
}

unsigned short int Scan::get_win_player_num() {
  return this->win_player_num;
}
