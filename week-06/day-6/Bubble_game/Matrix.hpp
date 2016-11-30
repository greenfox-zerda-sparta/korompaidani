#ifndef MATRIX_H
#define MATRIX_H

#include "Bubbles.hpp"

class Matrix
{
  private:
    const int MATRIX_SIZE = 10;
	  std::vector< std::vector<char> > matrix;
    std::vector<char> my_bubbles;
	  std::vector<int> bubble_pos_x;
	  std::vector<int> bubble_pos_y;
  public:
    Matrix(Bubbles b1);
    void draw_matrix();
    void get_bubble_info();
    void fill_empty_matrix();
};



#endif // MATRIX_H
