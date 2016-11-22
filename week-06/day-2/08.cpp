#include <iostream>
#include <string>
using namespace std;

// Create a fixed size stack. The stack can contain only 5 elements.
// You can push on the stack and pop from the stack.
// Write the push and pop methods so, that each throws an integer value if there is an error.
// Like when the stack is empty or full. Just make sure those are different values.
// Write a method called string interpretException(int exception) that returns the error message string for the integer.
//
// Illustrate in the main function both when it works fine and when exceptions occur.

struct Stack {
  int size = 0;
  double* data = NULL;
  const int size_max = 5;
};

Stack* stack_construct(double input[], int size) throw (const char*){
  Stack* data_ptr = new Stack;
  if (data_ptr->size > data_ptr->size_max) {
    throw "You cannot construct the stack with more than max_size element";
  }

  data_ptr->data = new double[size];
  for (int i = 0; i < size; i++) {
    data_ptr->data[i] = input[i];
  }
  data_ptr->size = size;
  return data_ptr;
};

void stack_push(Stack& stack, double value) throw (int) {
  stack.size++;
  if (stack.size > stack.size_max) {
    throw 9;
  }
  int new_size = stack.size;
  double* push_data = new double[new_size];
  for (int i = 0; i < new_size; i++) {
    push_data[i] = (i == new_size - 1) ? value : stack.data[i];
  }
  delete[] stack.data;
  stack.data = push_data;
};

double stack_pop(Stack& stack) throw (int) {
  if (stack.size == 0) {
    throw 0;
  }
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

int main() {
  try { //err_code 9: more the max element
    Stack s1;
    stack_push(s1, 8);
    stack_push(s1, 6);
    stack_push(s1, 8);
    stack_push(s1, 6);
    stack_push(s1, 8);
    stack_push(s1, 6);
    stack_push(s1, 3.6);

    cout << stack_pop(s1) << endl;
  }
  catch (int exc) {
    cout << "Error code is: " << exc << endl;
  }

  try { //err_code 0: stack is empty
    Stack s1;
    cout << stack_pop(s1) << endl;
  }
  catch (int exc) {
    cout << "Error code is: " << exc << endl;
  }

  try { //its okay
    Stack s1;

    stack_push(s1, 8);
    stack_push(s1, 6);
    stack_push(s1, 3.6);

    for (int i = 0; i < s1.size; i++) {
      cout << s1.data[i] << endl;
    }
    cout << stack_pop(s1) << endl;

  }
  catch (int exc) {
    cout << "Error code is: " << exc << endl;
  }

  return 0;
}
