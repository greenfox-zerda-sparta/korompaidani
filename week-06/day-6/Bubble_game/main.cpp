#include <iostream>
#include <string>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

#include "Bubbles.hpp"
#include "Matrix.hpp"

using namespace std;

int main() {
  srand(unsigned(time(0)));

  Bubbles b1(9);
  b1.shuffle_bubbles();
  Matrix m1(b1);
  m1.draw_matrix();


  m1.fill_empty_matrix();
  m1.draw_matrix();
  m1.get_bubble_info();


  for (int i = 0; i < 20; i++) {
    m1.run_on_y(0);
    m1.run_on_y(1);
    m1.run_on_y(2);
    m1.run_on_y(3);
    m1.run_on_x(4);
    m1.run_on_x(5);
    m1.run_on_x(6);
    m1.run_on_x(7);
    m1.run_on_x(8);
    m1.fill_matrix_by_pos();
    m1.draw_matrix();
    m1.get_bubble_info();
  }

  return 0;

	//Bubble Game!!!!
	//Create a class template that has the values and methods to operate our bubble game!
	//Our bubble game has a fix 10*10 square map, where our newly generated bubbles move in constant direction
	//they move with predefined x-y coordinates, which they take in their constructor
	//If they "hit" the wall multiply the correct direction "vector" with -1
	//The game has 10 bubbles
	//the bubbles start from random x-y coordinates, and can move 0-3 unit maximum in each direction
	//You have to run the games for 10 rounds
	//In each round the bubble move from their spot to the next spot pointed with its direction vector
	//After 10 rounds print how many times did the balls collide, and how many times did they hit the wall
  return 0;
}
