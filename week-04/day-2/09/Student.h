#include <iostream>
#include <string>
#ifndef STUDENT_H
#define STUDENT_H


class Student
{
  public:
    void add_grade(double in_grade);
    double get_average();
  private:
    unsigned short int grade_quant = 0;
    double grade = 0;
};

#endif // STUDENT_H

    // Create a student Class
    // that has a method `add_grade`, that takes a grade from 1 to 5
    // an other method `get_average`, that returns the average of the
    // grades
