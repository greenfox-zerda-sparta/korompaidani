#include "List.hpp"
#include "FunctionTools.hpp"

List::List(int argc, char**argv) {
  lines = 0;
  my_argc = argc;
  my_argv = char_star_array_to_string_array(argv, argc);
}

void List::test(){
  cout << "List class's my_argc number is:\t\t  |" << my_argc << "|" << endl;
  cout << "List class's *my_argv string elements are:\n";
  for (int i = 0; i < my_argc; i++) {
    cout << "\t\t\t\t\t  |" << this->my_argv[i] << "|" << endl;
  }
  if (my_argc > 0) {
    cout << my_argv[1] << endl;
  }
}
