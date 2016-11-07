#include <iostream>

using namespace std;

struct Stack {
  double* data = NULL;
  int size = 0;
  int position = 0;
};

Stack* stack_construct(double input[], int size) {
  Stack* data_ptr = new Stack;
  int i = 8;
  do {
    i = i * 2;
  }
  while (i + 1 <= size * 2);
  data_ptr->position = size;
  size = i;
  data_ptr->data = new double[size];
  for (int i = 0; i < size; i++) {
    if (i < data_ptr->position) {
      data_ptr->data[i] = input[i];
    }
  }
  data_ptr->size = size;
  return data_ptr;
};

void stack_push(Stack& stack, double value) {
  stack.data[stack.position] = value;
  stack.position++;

  if (stack.position > 0.8 * stack.size) {
    stack.size *= 2;
    double* push_data = new double[stack.size];
    for (int i = 0; i < stack.size; i++) {
      push_data[i] = stack.data[i];
    }
  delete[] stack.data;
  stack.data = push_data;
  }
};

double stack_pop(Stack& stack) {
  if (stack.position == 0) {
    return -1;
  }
  stack.position--;
  return stack.data[stack.position];
};

void stack_printer(Stack* input) {
  for (int i = 0; i < input->position; i++) {
    cout << input->data[i] << endl;
  }
  cout << endl << "The size is: " << input->size << endl;
  cout << "The position is: " << input->position << endl << endl;
}

int main(){
  double arr1[7] =  {1.1, 1.2, 2.5, 5.9, 1, 2, 3};

  Stack* stack_arr1 = stack_construct(arr1, 7);
  stack_printer(stack_arr1);

  stack_push(*stack_arr1, 62);
  stack_push(*stack_arr1, 5.3);
  stack_push(*stack_arr1, 1.8);
  stack_push(*stack_arr1, 9.5);
  stack_push(*stack_arr1, 640);
  stack_push(*stack_arr1, 12);

  stack_printer(stack_arr1);
  cout << "Stack pop result: " << stack_pop(*stack_arr1) << endl;
  stack_printer(stack_arr1);

  return 0;
}

/*
Implement a stack data-structure that stores doubles in C++,
and several functions that operate on stacks Each stack should have size property that stores how many elements are in the stack.
The length of the inner array should be independent form the size, to optimize on reallocation,
this case it does not need to reallocate each time on push.

Functions

Construct
Stack* stack_construct(double input[], int size);
It should dynamically allocate the Stack instance
It should set the size
It should dynamically allocate the double array
The length of the allocated array should be independent from the size, to optimize on the reallocation of the array
It should allocate at least a double length array then the size
The length of the array should be always some power of two and at least 16 (16, 32, 64, 128, ...)

Push
void stack_push(Stack& stack, double value);
It should push the value to the end of the stack
It should increment the size by 1
If the size exceeds the 80% of the current allocated length of the array it should
reallocate the size of the array to it's double

Pop
double stack_pop(Stack& stack);
It should return the value that was pushed the last time
It should decrement the size by 1
It should not resize the array
*/
