#include "Scan.hpp"

Scan::Scan() {
  this->win_player_num = 0;
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

void Scan::round_scan(Map& map, std::pair<int, int> coord, int player_num) {
  int counter = 0;
  int right = 0;
  int left = 0;
  int top = 0;
  int bottom = 0;
  /* I */
  std::cout << "vertical\n";
  if (coord.second - 5 < 0) {  
    top = 0 - (coord.second - 5);
  }
  if (coord.second + 5 > map.get_map_size() - 1) {
    bottom = (coord.second + 5) - (map.get_map_size() - 1);
  }

  for (int i = coord.second - 5 + top; i < coord.second + 5 - bottom; i++) {
    std::cout << map.get_map()[i][coord.first] << std::endl;
    if (map.get_map()[i][coord.first] == player_num) {
      counter++;
    }
    else {
      counter = 0;
    }
    if (counter == 5) {
      win_player_num = player_num;
      ///return;
    }
  }
  
  top = bottom = 0;
  
  /* _ */
  std::cout << "horizontal\n";
  if (coord.first - 5 < 0) {
    left = 0 - (coord.first - 5);
  }
  if (coord.first + 5 > map.get_map_size() - 1) {
    right = (coord.first + 5) - (map.get_map_size() - 1);
  }
  
  std::cout << std::endl;
  for (int i = coord.first - 5 + left; i < coord.first + 5 - right; i++) {
    std::cout << map.get_map()[coord.second][i] << " ";
  }

  left = right = 0;
  
  /* \ to down*/
  std::cout << std::endl << " \\ to down\n";
  if (coord.second - 5 < 0) {
    right = 0 - (coord.second - 5);
  }
  if (coord.first - 5 < 0) {
    bottom = 0 - (coord.first - 5);
  }
  if (coord.second + 5 > map.get_map_size() - 1) {
    left = (coord.second + 5) - (map.get_map_size() - 1);
  }
  if (coord.first + 5 > map.get_map_size() - 1) {
    top = (coord.first + 5) - (map.get_map_size() - 1);
  }

  std::cout << std::endl << std::endl;
  for (int i = -5 + (right) + (bottom); i < 6 - (left) - (top); i++) {
    std::cout << map.get_map()[coord.second + i][coord.first + i] << std::endl;
  }

  right = left = top = bottom = 0;
///
  /* \ to up*/
  std::cout << " \\ to up\n";
  if (coord.first - 5 < 0) {
    left = 0 - (coord.first - 5);
  }
  if (coord.second - 5 < 0) {
    top = 0 - (coord.second - 5);
  }

  std::cout << std::endl << std::endl;
  for (int i = 0; i < 6 - (left) - (top); i++) {
    std::cout << map.get_map()[coord.second - i][coord.first - i] << std::endl;
  }

  right = left = top = bottom = 0;
  
  /* / to down */
  std::cout << " / to down\n";
  if (coord.first + 5 > map.get_map_size() - 1) {
  right = (coord.first + 5) - (map.get_map_size() - 1);
  }
  if (coord.second + 5 > map.get_map_size() - 1) {
  bottom = (coord.second + 5) - (map.get_map_size() - 1);
  }
  if (coord.first - 5 < 0) {
  left = 0 - (coord.first - 5);
  }
  if (coord.second - 5 < 0) {
    top = 0 - (coord.second - 5);
  }
  std::cout << std::endl << std::endl;
  for (int i = -5 + (right) + (top); i < 6 - (bottom) - (left); i++) {
    std::cout << map.get_map()[coord.second + i][coord.first - i] << std::endl;
  }
///
  /* / to up */
  std::cout << " / to up\n";
  if (coord.first + 5 > map.get_map_size() - 1) {
    right = (coord.first + 5) - (map.get_map_size() - 1);
  }
  if (coord.second + 5 > map.get_map_size() - 1) {
    bottom = (coord.second + 5) - (map.get_map_size() - 1);
  }
  if (coord.first - 5 < 0) {
    left = 0 - (coord.first - 5);
  }
  if (coord.second - 5 < 0) {
    top = 0 - (coord.second - 5);
  }
  std::cout << std::endl << std::endl;
  for (int i = 0; i < 6 - (right) - (top); i++) {
    std::cout << map.get_map()[coord.second - i][coord.first + i] << std::endl;
  }
  
}

/*
int temp2 = -5;
for (int i = 0; i < 10; i++) {
std::cout << map.get_map()[coord.second + temp2 + right - bottom - left + top][coord.first - temp2 - right + bottom + left - top] << std::endl;
temp2++;
}
*/

std::pair<char, int> Scan::get_win_case() {
  return this->win_case;
}

unsigned short int Scan::get_win_player_num() {
  return this->win_player_num;
}