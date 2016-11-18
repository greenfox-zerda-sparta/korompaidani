#ifndef ERRORCODES_H
#define ERRORCODES_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void err_mess_with_code(int code) {
  switch (code) {
    case 1:
      cout << "No todos for today! :)" << endl;
      break;
    case 2:
      cout << "Please only one element a time!" << endl;
      break;
    case 3:
      cout << "Please write a new note if you use the \"-a\" command" << endl;
      break;
    case 4:
      cout << "The list is empty, you cannot remove items!" << endl;
      break;
    case 5:
      cout << "You have only 1 item. Type \"-r 1\" to remove it!" << endl;
      break;
    case 6:
      cout << "Please type only existing command!" << endl;
      break;
    case 7:
      cout << "Please type command in valid format!" << endl;
      break;
    case 8:
      cout << "Undefinied error!" << endl;
      break;
    case 9:
      cout << "The list is empty, you cannot complete any items!" << endl;
      break;
    case 10:
      cout << "You have only 1 item. Type \"-c 1\" to complete it!" << endl;
      break;
    case 11:
      cout << "The list is empty, you cannot uncomplete any item!" << endl;
      break;
    case 12:
      cout << "You have only 1 item. Type \"-u 1\" to uncomplete it!" << endl;
      break;
    case 13:
      cout << "Coming soon in next release!" << endl;
      break;
    default:
      cout << "Undefinied error!" << endl;
  }
}


void err_mess_with_int(int lines) {
  cout << "Please type a number between 1 and " << lines << "!" << endl;
}

void err_mess_with_char(char char_first_element) {
  cout << "char first element is: " << char_first_element << endl;
}

void message_empty(){
  cout << "Your list is empty!" << endl;
}

#endif // ERRORCODES_H
