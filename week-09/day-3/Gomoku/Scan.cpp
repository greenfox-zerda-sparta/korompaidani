#include "Scan.hpp"

Scan::Scan() {
}

bool Scan::horizontal(Map& map) {
  int temp = 1;
  int counter = 0;
  for (int i = 0; i < map.get_map().size(); i++) {
    for (int j = 0; j < map.get_map()[i].size(); j++) {
      if (temp == map.get_map()[i][j]) {
        counter++;
        if (counter == 5) {
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
