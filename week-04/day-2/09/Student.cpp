#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

void Student::add_grade(double in_grade) {
  this->grade += in_grade;
  this->grade_quant++;
};
double Student::get_average() {
  return this->grade / grade_quant;
};
