#include "List.hpp"
#include "FunctionTools.hpp"
#include "ErrorCodes.hpp"

List::List(int argc, char**argv) {
  filename = "todo.txt";
  filename_desc = "description.txt";
  commands = "larcudeh";
  lines = 0;
  checked = ' ';
  my_argc = argc;
  my_argv = char_star_array_to_string_array(argv, argc);
  lines = file_line_counter(filename);
  file_buffer = file_to_string_from_to(filename, lines, 1, lines);

}

void List::lists_all_the_tasks() {
  if (my_argc > 0) {
    if (lines != 0) {
      file_buffer = file_to_string_from_to(filename, lines, 1, lines);
      print_from_string(file_buffer, checked);
    }
    else {
      err_mess_with_code(1);
      lines = 0;
    }
  }
}

void List::add_new_task() {
  if (my_argc > 0) {
    if (my_argc == 2) {
      lines += 1;
      user_type_buffer = my_argv[1];
      file_buffer = file_buffer + user_type_buffer + checked;
      string_to_file(filename, file_buffer);
      print_from_string(file_buffer, checked);
    }
    else if (my_argc > 2) {
      err_mess_with_code(2);
    }
    else if (my_argc < 2) {
      err_mess_with_code(3);
    }
  }
}

void List::remove_task() {
  if (my_argc > 0) {
    user_type_buffer = my_argv[1];
    int user_num = int_from_string(user_type_buffer) - 1;
    if (lines == 0) {
      err_mess_with_code(4);
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
        err_mess_with_int(lines);
      }
      else if (lines == 1) {
        err_mess_with_code(5);
      }
    }
  }
}

void List::complete_list() {
  if (my_argc > 0) {
    user_type_buffer = my_argv[1];
    int user_num = int_from_string(user_type_buffer) - 1;
    if (lines == 0) {
      err_mess_with_code(9);
      return;
    }
    else if (user_num <= lines && user_num >= 0) {
      string temp_str = file_to_string_from_to(filename, lines, user_num + 1, user_num + 1);
      if (temp_str[temp_str.length() - 2]  == 'x') {
        cout << "This is X" << endl;
        checked = ' ';
      }
      else if (temp_str[temp_str.length() - 2]  == ' '){
        cout << "This is SPACE" << endl;
        checked = 'x';
      }
      file_buffer = file_to_string_from_to(filename, lines, 1, user_num);
      file_buffer += file_to_string_from_to_with_checker(filename, lines, user_num + 1, user_num + 1, checked);
      checked = ' ';
      file_buffer += file_to_string_from_to(filename, lines, user_num + 2, lines);
      string_to_file(filename, file_buffer);
      print_from_string(file_buffer, checked);
      return;
    }
    else {
      if (lines != 1) {
        err_mess_with_int(lines);
      }
      else if (lines == 1) {
        err_mess_with_code(10);
      }
    }
  }
}

void List::un_complete_list() {
  if (my_argc > 0) {
    user_type_buffer = my_argv[1];
    int user_num = int_from_string(user_type_buffer) - 1;
    if (lines == 0) {
      cout << "The list is empty, you cannot remove items!" << endl;
      return;
    }
    else if (user_num <= lines && user_num >= 0) {

      file_buffer = file_to_string_from_to(filename, lines, 1, user_num);
      file_buffer += file_to_string_from_to_with_checker(filename, lines, user_num + 1, user_num + 1, checked);
      file_buffer += file_to_string_from_to(filename, lines, user_num + 2, lines);
      string_to_file(filename, file_buffer);
      print_from_string(file_buffer, checked);
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

void List::del_completed_list() {
  if (my_argc > 0) {
    err_mess_with_code(13);
  }
}

void List::empty_list() {
  empty_file(filename);
  lines = 0;
  message_empty();
}

void List::task_manager() {
  if (my_argc > 0) {
    char char_first_element = '!';
    if (is_it_valid_typing_for_first_element(my_argv[0]) == true) {
      if (is_command_valid(one_letter_from_string(my_argv[0]), this->commands) == true) {
        char_first_element = one_letter_from_string(my_argv[0]);
      }
      else {
        err_mess_with_code(6);
        cout << file_to_string_entire(this->filename_desc);
        return;
      }
    }
    else {
      err_mess_with_code(7);
      cout << file_to_string_entire(this->filename_desc);
      return;
    }
    switch (char_first_element) {
      case 'l': List::lists_all_the_tasks();
        break;
      case 'a': List::add_new_task();
        break;
      case 'r': List::remove_task();
        break;
      case 'c': List::complete_list();
        break;
      case 'u': List::un_complete_list();
        break;
      case 'd': List::del_completed_list();
        break;
      case 'e': List::empty_list();
        break;
      case 'h': cout << endl << file_to_string_entire(this->filename_desc) << endl;
        break;
      default: err_mess_with_code(8);
    }
  }
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
