#include "sudoku.h"

#include <cmath>

#include <set>

#include <algorithm>



bool is_square(int number);

bool is_vector_size_valid(std::vector<int>& v);

bool is_vector_content_valid(std::vector<int>& v);



bool sudoku_is_valid(std::vector<int>& v) {

  return is_vector_size_valid(v) && is_vector_content_valid(v);

}



bool is_square(int number) {

  return sqrt(number) == (int)sqrt(number);

}



bool is_vector_size_valid(std::vector<int>& v) {

  return (!v.empty()) && is_square(v.size());

}



bool is_vector_content_valid(std::vector<int>& v) {

  bool is_in_range = std::all_of(v.begin(), v.end(), [&v](int i) {return i <= v.size() && i > 0;});

  std::set<int> buffer(v.begin(), v.end());

  return buffer.size() == v.size() && is_in_range;

}