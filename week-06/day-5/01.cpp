#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_two_dim_vect(vector< vector<int> > &matrix) {
  for (unsigned int o = 0; o < matrix.size(); o++) {
    if (o == 0) {
      cout << "   ";
      char column_lett = 'a';
      for(int colum_num = 0; colum_num < matrix[o].size(); colum_num++) {
        cout << column_lett++ << "|";
      }
      cout << endl << endl;
    }
    cout << o + 1 << ". ";
    for (unsigned int i = 0; i < matrix[o].size(); i++) {
      cout << matrix[o][i] << "|";
    }
    cout << endl;
  }
  cout << endl;
}

void coordinate_increase_by_one_the_outer(vector< vector<int> > &matrix, unsigned int x, unsigned int y, int number) {
  matrix[x][y] = number;
}

unsigned int first_dim_size_checker(vector< vector<int> > &matrix, unsigned int input) throw (unsigned int) {
  if (input < matrix.size()) {
    return input;
  }
  throw matrix.size();
}

unsigned int second_dim_size_checker(vector< vector<int> > &matrix, unsigned int x, unsigned int y) throw (unsigned int) {
  if (y < matrix[x].size()) {
    return y;
  }
  throw matrix[x].size();
}

int main() {
	try {
	  vector< vector<int> > my_vector(5, vector<int>(5, 0));
	  cout << "Hi, this is the matrix:" << endl;
	  print_two_dim_vect(my_vector);

    cout << endl;

    unsigned int x;
	  unsigned int y;

    cout << "Please give me the x coordinate: ";
    cin >> x;
    x = first_dim_size_checker(my_vector, x);

    cout << "Please give me the y coordinate: ";
    cin >> y;
    y = second_dim_size_checker(my_vector, x, y);

    coordinate_increase_by_one_the_outer(my_vector, x, y, 2);
    print_two_dim_vect(my_vector);

    int user;
    cin >> user;
	}
	catch (unsigned int excp) {
		cout << "You can type from 0-" << excp << endl;
		    int user;
		    cin >> user;
	}

  return 0;
}
