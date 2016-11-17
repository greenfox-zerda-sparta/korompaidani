#include <iostream>
#include  <string>

#ifndef LIST_H
#define LIST_H

using namespace std;

class List {
  private:
    int lines;
    string* buffer;
    char user_choise;
    string filename;
    string filename_desc;
    int user_number;
    int my_argc;
  public:

    void show_my_argc();
    void argv_to_buffer(char** argv, int argc);
    void test();
    List(int argc);
};

#endif // LIST_H
