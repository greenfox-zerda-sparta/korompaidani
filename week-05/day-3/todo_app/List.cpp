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
      file_buffer = file_to_string_entire(filename);
      print_from_string(file_buffer, checked);
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
      file_buffer = file_buffer + user_type_buffer;
      string_to_file(filename, file_buffer);
      print_from_string(file_buffer, checked);
    }
    else {
      cout << "please only one element a time!" << endl;
    }
  }
}

void List::remove_task() {
  if (my_argc > 0) {
    cout << "lines: " << lines << endl;
    user_type_buffer = my_argv[1];
    int user_num = int_from_string(user_type_buffer) - 1;
    file_buffer = file_to_string_from_to(filename, lines, 1, user_num) + file_to_string_from_to(filename, lines, user_num + 2, lines);
    cout << "lines: " << lines << endl;
    string_to_file(filename, file_buffer);
    print_from_string(file_buffer, checked);
  }
}

void List::task_manager() {
  if (my_argc > 0) {
    char char_first_element = '!';
    int num_temp;
    string str_temp;
    if (is_it_valid_typing_for_first_element(my_argv[0]) == true) {
      char_first_element = one_letter_from_string(my_argv[0]);
    }
    else {
      cout << "Please type only valid command!";
    }
    switch (char_first_element) {
      case 'l': List::lists_all_the_tasks();
        break;
      /*case 'a':
        break;
      case 'r':
        break;
      case 'c':
        break;*/
      default: cout << "something";
    }
  }
}
