#include <iostream>
#include <string>
#include "List.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  argc = argc -1; // it seems under windows the char** argv owns the .exe-s directory path on 0. place
  string filename = "todo.txt";

  List l1(argc);

  l1.show_my_argc();
  l1.argv_to_buffer(argv, argc);
  //l1.test();

  return 0;
}
