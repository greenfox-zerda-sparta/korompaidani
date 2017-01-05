#include "Scan.hpp"

Scan::Scan() {
  this->win_player_num = 0;
}

bool Scan::vertical(Map& map, std::pair<int, int> coord, int player_num) {
  int counter = 0;
  borders b;
  std::cout << "vertical\n";
  
  if (coord.second - 5 < 0) {
    b.top = 0 - (coord.second - 5);
  }
  if (coord.second + 5 > map.get_map_size() - 1) {
    b.bottom = (coord.second + 5) - (map.get_map_size() - 1);
  }

  for (int i = coord.second - 5 + (b.top); i < coord.second + 6 - (b.bottom); i++) {
    std::cout << map.get_map()[i][coord.first] << std::endl;
    if (map.get_map()[i][coord.first] == player_num) {
      counter++;
    }
    else {
      counter = 0;
    }
    if (counter == 5) {
      win_player_num = player_num;
      return true;
    }
  }
  return false;
}

bool Scan::horizontal(Map& map, std::pair<int, int> coord, int player_num) {
  int counter = 0;
  borders b;

  std::cout << "horizontal\n";
  if (coord.first - 5 < 0) {
    b.left = 0 - (coord.first - 5);
  }
  if (coord.first + 5 > map.get_map_size() - 1) {
    b.right = (coord.first + 5) - (map.get_map_size() - 1);
  }

  std::cout << std::endl;
  for (int i = coord.first - 5 + (b.left); i < coord.first + 6 - (b.right); i++) {
    std::cout << map.get_map()[coord.second][i] << " ";
    if (map.get_map()[coord.second][i] == player_num) {
      counter++;
    }
    else {
      counter = 0;
    }
    if (counter == 5) {
      win_player_num = player_num;
      return true;
    }
  }
  return false;
}

bool Scan::diagonal_se(Map& map, std::pair<int, int> coord, int player_num) {
  int counter = 0;
  borders b;
  std::cout << std::endl << " \\ to down\n";
  if (coord.second - 5 < 0) {
    b.right = 0 - (coord.second - 5);
  }
  if (coord.first - 5 < 0) {
    b.bottom = 0 - (coord.first - 5);
  }
  if (coord.second + 5 > map.get_map_size() - 1) {
    b.left = (coord.second + 5) - (map.get_map_size() - 1);
  }
  if (coord.first + 5 > map.get_map_size() - 1) {
    b.top = (coord.first + 5) - (map.get_map_size() - 1);
  }

  std::cout << std::endl << std::endl;
  for (int i = -5 + (b.right) + (b.bottom); i < 6 - (b.left) - (b.top); i++) {
    std::cout << map.get_map()[coord.second + i][coord.first + i] << std::endl;
    if (map.get_map()[coord.second + i][coord.first + i] == player_num) {
      counter++;
    }
    else {
      counter = 0;
    }
    if (counter == 5) {
      win_player_num = player_num;
      return true;
    }
  }
  return false;
}

bool Scan::diagonal_nw(Map& map, std::pair<int, int> coord, int player_num) {
  int counter = 0;
  borders b;

  std::cout << " \\ to up\n";
  if (coord.first - 5 < 0) {
    b.left = 0 - (coord.first - 5);
  }
  if (coord.second - 5 < 0) {
    b.top = 0 - (coord.second - 5);
  }

  std::cout << std::endl << std::endl;
  for (int i = 0; i < 6 - (b.left) - (b.top); i++) {
    std::cout << map.get_map()[coord.second - i][coord.first - i] << std::endl;
    if (map.get_map()[coord.second - i][coord.first - i] == player_num) {
      counter++;
    }
    else {
      counter = 0;
      std::cout << "counter is: " << counter << std::endl;
    }
    if (counter == 5) {
      win_player_num = player_num;
      return true;
    }
  }
  return false;
}

bool Scan::diagonal_sw(Map& map, std::pair<int, int> coord, int player_num) {
  int counter = 0;
  borders b;

  std::cout << " / to down\n";
  if (coord.first + 5 > map.get_map_size() - 1) {
    b.right = (coord.first + 5) - (map.get_map_size() - 1);
  }
  if (coord.second + 5 > map.get_map_size() - 1) {
    b.bottom = (coord.second + 5) - (map.get_map_size() - 1);
  }
  if (coord.first - 5 < 0) {
    b.left = 0 - (coord.first - 5);
  }
  if (coord.second - 5 < 0) {
    b.top = 0 - (coord.second - 5);
  }
  std::cout << std::endl << std::endl;
  for (int i = -5 + (b.right) + (b.top); i < 6 - (b.bottom) - (b.left); i++) {
    std::cout << map.get_map()[coord.second + i][coord.first - i] << std::endl;
    if (map.get_map()[coord.second + i][coord.first - i] == player_num) {
      counter++;
    }
    else {
      counter = 0;
    }
    if (counter == 5) {
      win_player_num = player_num;
      return true;
    }
  }
  return false;
}

bool Scan::diagonal_ne(Map& map, std::pair<int, int> coord, int player_num) {
  int counter = 0;
  borders b;

  std::cout << " / to up\n";
  if (coord.first + 5 > map.get_map_size() - 1) {
    b.right = (coord.first + 5) - (map.get_map_size() - 1);
  }
  if (coord.second + 5 > map.get_map_size() - 1) {
    b.bottom = (coord.second + 5) - (map.get_map_size() - 1);
  }
  if (coord.first - 5 < 0) {
    b.left = 0 - (coord.first - 5);
  }
  if (coord.second - 5 < 0) {
    b.top = 0 - (coord.second - 5);
  }
  std::cout << std::endl << std::endl;
  for (int i = 0; i < 6 - (b.right) - (b.top); i++) {
    std::cout << map.get_map()[coord.second - i][coord.first + i] << std::endl;
    if (map.get_map()[coord.second - i][coord.first + i] == player_num) {
      counter++;
    }
    else {
      counter = 0;
    }
    if (counter == 5) {
      win_player_num = player_num;
      return true;
    }
  }
  return false;
}

void Scan::round_scan(Map& map, std::pair<int, int> coord, int player_num) {
  vertical(map, coord, player_num);
  horizontal(map, coord, player_num);
  diagonal_se(map, coord, player_num);
  diagonal_nw(map, coord, player_num);
  diagonal_sw(map, coord, player_num);
  diagonal_ne(map, coord, player_num);
}

unsigned short int Scan::get_win_player_num() {
  return this->win_player_num;
}

void Scan::reset_win_player_num() {
  this->win_player_num = 0;
}
