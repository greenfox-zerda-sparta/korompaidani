#include <iostream>
#include <string>

#include "Stack.h"
using namespace std;

Stack::Stack(double input[], int size) {
  data = new double[size];
  for (int i = 0; i < size; i++) {
    data[i] = input[i];
  }
  this->size = size;
};

void Stack::get_Stack_data() {
  for (int i = 0; i < this->size; i++) {
    cout << this->data[i] << endl;
  }
};

void Stack::stack_push(double input) {
  this->size++;
  double* push_data = new double[this->size];
  for (int i = 0; i < this->size; i++) {
    push_data[i] = (i == this->size - 1) ? input : this->data[i];
  }
  delete[] this->data;
  this->data = push_data;
};

double Stack::stack_pop() {
  double last_item = this->data[this->size - 1];
  this->size--;
  double* last_data = new double[this->size];
  for (int i  = 0; i < this->size; i++) {
    last_data[i] = this->data[i];
  }
  delete[] this->data;
  this->data = last_data;
  return last_item;
};

int Stack::get_size() {
  return this->size;
};
