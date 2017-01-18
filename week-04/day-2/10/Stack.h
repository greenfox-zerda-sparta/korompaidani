#include <iostream>
#include <string>

#ifndef STACK_H
#define STACK_H

using namespace std;

class Stack
{
  public:
    Stack(double input[], int size);
    void get_Stack_data();
    int get_size();
    void stack_push(double input);
    double stack_pop();
  private:
    int size = 0;
    double* data = NULL;
};

#endif // STACK_H
