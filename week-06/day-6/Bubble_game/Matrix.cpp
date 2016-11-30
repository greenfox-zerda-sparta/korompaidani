#include "Matrix.hpp"
#include <iostream>
#include "Bubbles.hpp"
#include <vector>

#include <time.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

Matrix::Matrix(Bubbles b1) {
  my_bubbles.resize(b1.get_bubble_quant());
  for (int i = 0; i < my_bubbles.size(); i++) {
    my_bubbles[i] = b1.get_bubbles()[i];
  }
  matrix.resize(MATRIX_SIZE);
  for (int i = 0; i < MATRIX_SIZE; i++) {
    matrix[i].resize(MATRIX_SIZE, '.');
  }
  bubble_pos_x.resize(my_bubbles.size(), 0);
  bubble_pos_y.resize(my_bubbles.size(), 0);
  b1.~Bubbles();
}

void Matrix::draw_matrix() {
  cout << "This is the matrix:" << endl;
  for (int o = 0; o < matrix.size(); o++) {
    for (int i = 0; i < matrix[o].size(); i++) {
      cout << matrix[o][i] << ' ';
    }
    cout << endl;
  }
}

void Matrix::get_bubble_info() {
  cout << "list of bubbles =\t|";
  for (int i = 0; i < my_bubbles.size(); i++) {
    cout << my_bubbles[i] << "|";
  }
  cout << endl;
  cout << "bubble pos x =\t\t|";
  for (int  i = 0; i < bubble_pos_x.size(); i++) {
      cout << bubble_pos_x[i] << "|";
  }
  cout << endl;
  cout << "bubble pos y =\t\t|";
  for (int  i = 0; i < bubble_pos_y.size(); i++) {
    cout << bubble_pos_y[i] << "|";
    }
  cout << endl;
}

void Matrix::fill_empty_matrix() {
  for (int i = 0; i < my_bubbles.size(); i++) {
    int temp_pos_x = rand() % MATRIX_SIZE;
    int temp_pos_y = rand() % MATRIX_SIZE;
    if (matrix[temp_pos_x][temp_pos_y] == '.') {
      matrix[temp_pos_x][temp_pos_y] = my_bubbles[i];
      bubble_pos_x[i] = temp_pos_x;
      bubble_pos_y[i] = temp_pos_y;
    }
    else {
      do {
        temp_pos_x = rand() % MATRIX_SIZE;
        temp_pos_y = rand() % MATRIX_SIZE;
      }
      while (matrix[temp_pos_x][temp_pos_y] != '.');
      matrix[temp_pos_x][temp_pos_y] = my_bubbles[i];
      bubble_pos_x[i] = temp_pos_x;
      bubble_pos_y[i] = temp_pos_y;
    }
  }
}
