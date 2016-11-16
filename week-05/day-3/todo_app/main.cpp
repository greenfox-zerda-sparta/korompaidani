#include <iostream>
#include <string>
#include "FunctionTools.hpp"
#include "List.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  string filename = "todo.txt";

 // cout << file_to_string_entire(filename);
 // cout << file_line_counter(filename);
 // cout << file_to_string_to(filename, file_line_counter(filename), 3);
  cout << file_to_string_from_to(filename, file_line_counter(filename), -9, 9);
  cout << file_to_string_entire("description.txt");
 // cout << string_to_file(filename, file_to_string_entire("description.txt"));



  return 0;
}
