#include "List.hpp"
#include "FunctionTools.hpp"

List::List(int argc, char**argv) {
  lines = 0;
  my_argc = argc;
  my_argv = char_star_array_to_string_array(argv, argc);
  filename = "todo.txt";
  filename_desc = "description.txt";
  commands = "larce";
  file_buffer = file_to_string_entire(filename);
  lines = file_line_counter(filename);
  checked = ' ';
}

void List::test(){
  cout << "List class's my_argc number is:\t\t  |" << my_argc << "|" << endl;
  cout << "List class's *my_argv string elements are:\n";
  /*for (int i = 0; i < my_argc; i++) {
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
  }*/
  cout << "Lines = " << lines << endl;
}

void List::lists_all_the_tasks() {
  if (my_argc > 0) {
    if (lines != 0) {
      file_buffer = file_to_string_entire(filename);
      print_from_string(file_buffer, checked);
    }
    else {
      cout << "No todos for today! :)" << endl;
      lines = 0;
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
    else if (my_argc > 2) {
      cout << "Please only one element a time!" << endl;
    }
    else if (my_argc < 2) {
      cout << "Please write a new note if you use the \"-a\" command" << endl;
    }
  }
}

void List::remove_task() {
  if (my_argc > 0) {
    user_type_buffer = my_argv[1];
    int user_num = int_from_string(user_type_buffer) - 1;
    if (lines == 0) {
      cout << "The list is empty, you cannot remove items!" << endl;
      return;
    }
    else if (user_num <= lines && user_num >= 0) {
      file_buffer = file_to_string_from_to(filename, lines, 1, user_num) + file_to_string_from_to(filename, lines, user_num + 2, lines);
      string_to_file(filename, file_buffer);
      print_from_string(file_buffer, checked);
      lines--;
      return;
    }
    else {
      if (lines != 1) {
        cout << "Please type a number between 1 and " << lines << "!" << endl;
      }
      else if (lines == 1) {
        cout << "You have only 1 item. Type \"-r 1\" to remove it!" << endl;
      }
    }
  }
}

void List::empty_list() {
  empty_file(filename);
  lines = 0;
  cout << "Your list is empty!" << endl;
}

void List::task_manager() {
  if (my_argc > 0) {
    char char_first_element = '!';
    if (is_it_valid_typing_for_first_element(my_argv[0]) == true) {
      if (is_command_valid(one_letter_from_string(my_argv[0]), this->commands) == true) {
        char_first_element = one_letter_from_string(my_argv[0]);
      }
      else {
        cout << "Please type only existing command!" << endl;
        cout << file_to_string_entire(this->filename_desc);
        return;
      }
    }
    else {
      cout << "Please type command in valid format!";
      cout << file_to_string_entire(this->filename_desc);
      return;
    }
    cout << "char first element is: " << char_first_element << endl;
    switch (char_first_element) {
      case 'l': List::lists_all_the_tasks();
        break;
      case 'a': List::add_new_task();
        break;
      case 'r': List::remove_task();
        break;
      /*case 'c':
        break;*/
      case 'e': List::empty_list();
        break;
      default: cout << "something";
    }
  }
}
