#include <iostream>

using namespace std;

struct Stack {
  double* data = NULL;
  int size = 0;
};

Stack* stack_construct(double input[], int size) {
  Stack* data_ptr = new Stack;
  data_ptr->data = new double[size];
  for (int i = 0; i < size; i++) {
    data_ptr->data[i] = input[i];
  }
  data_ptr->size = size;
  return data_ptr;
};

void stack_printer(Stack* input) {
  for (int i = 0; i < input->size; i++) {
    cout << input->data[i] << endl;
  }
}


int main(){
  double arr1[4] =  {1.1, 1.2, 2.5, 5.9};

  Stack* stack_arr1 = stack_construct(arr1, 4);

  stack_printer(stack_arr1);




  return 0;
}

/*
Implement a stack data-structure that stores doubles in C++,
and several functions that operate on stacks Each stack should have size property that stores how many elements are in the stack.
The length of the inner array should be independent form the size, to optimize on reallocation,
this case it does not need to reallocate each time on push.

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
If the size exceeds the 80% of the current allocated length of the array it should reallocate the size of the array to it's double

Pop
double stack_pop(Stack& stack);
It should return the value that was pushed the last time
It should decrement the size by 1
It should not resize the array
*/
