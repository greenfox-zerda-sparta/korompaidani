#ifndef PRINT_BUBBLES_H
#define PRINT_BUBBLES_H

#include "Bubbles.hpp"

class Print_bubbles {
  public:
    Print_bubbles();
  private:
    void print_two_dim_vect(std::vector< std::vector<int> > &matrix);
    std::vector< std::vector<int> > matrix;
};

#endif // PRINT_BUBBLES_H
