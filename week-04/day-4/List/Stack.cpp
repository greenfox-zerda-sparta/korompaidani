#include <iostream>
#include <string>
#include "Stack.h"
#include "Intlist.h"

using namespace std;

Stack::Stack(int array[], int size) {
  this->mLength = size;
  this->data = new int[size];
  for (int i = 0; i < size; i++) {
    this->data[i] = array[i];
  }
}

void Stack::append(int _a) {
};

void Stack::insert(int _idx, int _a) {
};

int Stack::getFirst() {
};

int Stack::getLast() {
};

int Stack::getLength() {
};

bool Stack::isEmpty() {
};

int Stack::getArrElement(int i) {
  return data[i];
};

int Stack::getArray() {
  return *data;
};
