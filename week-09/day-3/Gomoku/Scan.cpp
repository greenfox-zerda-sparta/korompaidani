#include "Scan.hpp"

Scan::Scan() {
  this->win_player_num = 1;
}

bool Scan::horizontal(Map& map) {
  bool exit_if_false = true;
  int counter = 0;
  for (int i = 0; i < map.get_map().size(); i++) {
    for (int j = 0; j < map.get_map()[i].size(); j++) {
      if (map.get_map()[i][j] == win_player_num) {
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
  for (int i = 0; i < map.get_map().size(); i++) {
    for (int j = 0; j < map.get_map()[i].size(); j++) {
      lines = i + 1;
      if (map.get_map()[i][j] != 0) {
        counter++;
        while (19 - i - lines > 4) {
          if (map.get_map()[lines][j] != 0) {
            counter++;
            std::cout << "the counter is: " << counter << std::endl;          
          }
          lines++;
        }
        if (counter == 5) {
          this->win_case.first = 'v';
          this->win_case.second = i + 4;
          this->win_player_num = map.get_map()[i][j];
          return true;
        }
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