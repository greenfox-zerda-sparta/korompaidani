#include "Bubbles.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

Bubbles::Bubbles(int usernum) {
  bubble_quant = usernum;
  generate_bubble_chars(bubble_quant);
};

Bubbles::~Bubbles(){
  delete [] get_bubbles();
}

void Bubbles::generate_bubble_chars(int bubble_quant) {
  char ch = '1';
  for (int i = 0; i < bubble_quant; i++) {
    bubbles.push_back(ch++);
  }
};

void Bubbles::shuffle_bubbles() {
  random_shuffle (bubbles.begin(), bubbles.end());
}

char* Bubbles::get_bubbles() {
  char* temp = new char[bubbles.size()];
  for (int i = 0; i < bubbles.size(); i++) {
    temp[i] = bubbles[i];
  }
  return temp;
}

int Bubbles::get_bubble_quant() {
  return bubble_quant;
}
