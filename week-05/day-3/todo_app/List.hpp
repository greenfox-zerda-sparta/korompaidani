#include <iostream>
#include  <string>

#ifndef LIST_H
#define LIST_H

using namespace std;

class List {
  private:
    string* my_argv;
    int my_argc;
    char user_choise;
    int lines;
    string buffer;
    string filename;
    string filename_desc;
    int user_number;
  public:
    List(int argc, char**argv);
    void test();
};

#endif // LIST_H
