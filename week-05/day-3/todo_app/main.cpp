#include <iostream>
#include <string>
#include "List.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  argc = argc -1; // it seems under windows the char** argv owns the .exe-s directory path on 0. place
  string filename = "todo.txt";

  List l1(argc, argv);
  l1.test();


  //is_string_only_number_test("129") == true ? cout << "true" : cout << "false";
  return 0;
}
