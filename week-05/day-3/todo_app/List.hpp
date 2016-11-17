#include <iostream>
#include  <string>

#ifndef LIST_H
#define LIST_H

using namespace std;

class List {
  private:
    string* my_argv;
    int my_argc;
    string commands;
    char user_choise;
    int user_number;
    string user_type_buffer;
    int lines;
    string file_buffer;
    string filename;
    string filename_desc;
    char checked;
  public:
    List(int argc, char**argv);
    void test();
    void lists_all_the_tasks();
    void add_new_task();
    void remove_task();
    void task_manager();
};

#endif // LIST_H
