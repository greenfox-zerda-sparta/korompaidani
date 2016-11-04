#include <iostream>

using namespace std;

struct Stack {
  int size = 0;
  double* data = NULL;
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

void stack_push(Stack& stack, double value) {
  stack.size++;
  int new_size = stack.size;
  double* push_data = new double[new_size];
  for (int i = 0; i < new_size; i++) {
    push_data[i] = (i == new_size - 1) ? value : stack.data[i];
  }
  delete[] stack.data;
  stack.data = push_data;
};

double stack_pop(Stack& stack) {
  double last_item = stack.data[stack.size - 1];
  stack.size--;
  int new_size = stack.size;
  double* pull_last_data = new double[new_size];
  for (int i  = 0; i < new_size; i++) {
    pull_last_data[i] = stack.data[i];
  }
  delete[] stack.data;
  stack.data = pull_last_data;
  return last_item;
};

bool is_empty(Stack& stack);

int main() {

  double arr[3] = {88, 5, 19};
  int size =  sizeof(arr) / sizeof(double);

  Stack* first = stack_construct(arr, size);
  stack_push(*first, 2);
  stack_push(*first, 4);

  //stack_pop(*first);

  for (int i = 0; i < 5;  i++) {
    cout << i << ". index cont: " << first->data[i] << endl;
  }
  cout << "size: " << first->size;


    /*Stack
    Implement a stack data-structure that stores doubles in C++,
    and several functions that operate on stacks Each stack should have size
    property that stores how many elements are in the stack.*/

    /*Functions
    Construct
    It should dynamically allocate the Stack instance
    It should set the size
    It should dynamically allocate the double array*/

    /*Push
    It should push the value to the end of the stack
    It should increment the size by 1
    It should reallocate the array inside by the incremented size, and copy it's values*/

    /*Pop
    It should return the value that was pushed the last time
    It should decrement the size by 1
    It should reallocate the array inside by the decremented size, and copy it's values
    Is empty*/

    /*It should return true if the stack is empty and false otherwise*/

  return 0;
}
