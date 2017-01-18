#include <iostream>

using namespace std;

enum Months{
  JANUARY,
  FEBRUARY.
  MARCH,
  APRIL
};

int get_days_since_date(int year, month, int day) {
  if(year % 4 == 0 && month == FEBRUARY)
  };

int main() {
  cout << get_days_since_date(2006, 3, 12);
  return 0;
}
