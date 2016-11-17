#include "List.hpp"
#include "FunctionTools.hpp"

List::List(int argc) {
  lines = 0;
  my_argc = argc;
}

void List::show_my_argc() {
  cout << "This is: " << my_argc << endl;
};

void List::argv_to_buffer(char** argv, int argc) {
  buffer = char_star_array_to_string_array(argv, argc);
};

void List::test(){
  for (int i = 0; i < my_argc; i++) {
    cout << this->buffer[i] << endl;
  }
};
