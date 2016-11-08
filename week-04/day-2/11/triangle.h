#include <iostream>
#include <string>
#ifndef TRIANGLE_H
#define TRIANGLE_H

using namespace std;

class triangle
{
  public:
    void stardrawer(int in_length);
    void get_length();
  private:
    int length = 0;
};

#endif // TRIANGLE_H
