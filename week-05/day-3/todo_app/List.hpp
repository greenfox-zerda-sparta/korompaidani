#include <iostream>

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
  public:
    List();
};

#endif // LIST_H
