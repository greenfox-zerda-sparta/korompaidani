#include <iostream>
#include <string>
#include "List.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  argc = argc -1; // it seems under windows the char** argv owns the .exe-s directory path on 0. place
  string filename = "todo.txt";

  List l1(argc, argv);
  // l1.test();
  l1.add_new_task();
  // l1.test();


  //is_command_valid2('i', "dian") == true ? cout << "true" : cout << "false";
  return 0;
}
