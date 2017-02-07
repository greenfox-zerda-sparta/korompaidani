#pragma once
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <vector>
#include "Node.hpp"
#include "Singleton.hpp"

using namespace std;

class Path_finder {
private:
public:
  Path_finder();
  std::string pathFind(const int& start_x, const int& start_y, const int& finish_x, const int& finish_y);
  void route_planning(int start_x, int start_y, int finish_x, int finish_y);
  void initialize_tile_map();
  void clean_tile_map();
  void fill_with_plus_pattern();
  void print_map();
  void set_coord_on_map(int x, int y);
  ~Path_finder();
};

