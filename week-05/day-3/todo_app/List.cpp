#include "List.hpp"
#include "FunctionTools.hpp"

List::List(int argc, char**argv) {
  lines = 0;
  my_argc = argc;
  my_argv = char_star_array_to_string_array(argv, argc);
  filename = "todo.txt";
  filename_desc = "description.txt";
  commands = "larc";
  file_buffer = file_to_string_entire(filename);
  lines = file_line_counter(filename);
  checked = ' ';
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
  cout << "The filename is: " << filename << endl;

  if ((file_to_string_entire(filename))[0] == '!') {
    cout <<  "No todos for today!" << endl;;
  }
  else {
    cout << file_to_string_entire(filename);
  }
  cout << "Lines = " << lines << endl;
}

void List::lists_all_the_tasks() {
  if (my_argc > 0) {
    if (file_to_string_entire(filename)[0] != '!') {
      cout << file_to_string_entire(filename) << endl;
    }
    else {
      cout << "No todos for today! :)" << endl;
    }
  }
}

void List::add_new_task() {
  if (my_argc > 0) {
    if (my_argc == 2) {
      lines += 1;
      user_type_buffer = my_argv[1];
      file_buffer = file_buffer + string_from_int(lines) + " - [" + checked + "] " + user_type_buffer;
      string_to_file(filename, file_buffer);
      cout << file_buffer;
    }
    else {
      cout << "please only one element a time!" << endl;
    }
  }
}

