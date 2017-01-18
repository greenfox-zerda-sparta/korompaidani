#include <iostream>
#include <string>
#include <vector>

using namespace std;

void increase_by_one_the_inner(vector< vector<int> > &matrix, int user_int) {
  for (unsigned int o = 0; o < matrix.size(); o++) {
    matrix[o].push_back(user_int);
  }
}

void increase_by_one_the_outer(vector< vector<int> > &matrix, vector<int> &user_vector) {
  matrix.push_back(user_vector);
}

void at_increase_by_one_the_outer(vector< vector<int> > &matrix, vector<int> &user_vector, unsigned int where) {
  matrix.insert(matrix.begin() + where, user_vector);
}

void coordinate_increase_by_one_the_outer(vector< vector<int> > &matrix, unsigned int x, unsigned int y, int number) {
  matrix[x][y] = number;
}

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

void print_three_dim_vect(vector<vector< vector<int> > > &matrix) {
  for (unsigned int first = 0; first < matrix.size(); first++) {
    for (unsigned int second = 0; second < matrix[second].size(); second++) {
      for (int i = 0; i < 2; i++) {
        cout << "/";
      }
      for (unsigned int third = 0; third < matrix[second][third].size(); third++)
        cout << matrix[first][second][third] << "|";
    }
    cout << endl;
  }
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
/*
  vector< vector<int> > my_vector(5, vector<int>(5, 0));

  print_two_dim_vect(my_vector);

  increase_by_one_the_inner(my_vector,5);
  print_two_dim_vect(my_vector);

  vector<int> my_int_vector(6, 0);
  /*increase_by_one_the_outer(my_vector, my_int_vector);
  print_two_dim_vect(my_vector);

  at_increase_by_one_the_outer(my_vector, my_int_vector, 3);
  print_two_dim_vect(my_vector);

  coordinate_increase_by_one_the_outer(my_vector, 3, 3, 5);
  print_two_dim_vect(my_vector);
*/

  vector<vector<vector<int> > > my_three_dim_vect (5,vector<vector<int> >(3,vector <int>(2,0)));

  print_three_dim_vect(my_three_dim_vect);


	//create a vector of vector of integers
	//the inner vectors have 5 integers, all of them 0
	//the outer vector is holding 5 vectors
	//create a function which increase the given inner vector elements by 1 (one inside vector, holding five 0)



  return 0;
}
