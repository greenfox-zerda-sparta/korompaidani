#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool ascending_vector(int i, int j) {
  return i < j;
}

int main() {
	//find how much integer divisor 2400 has
	//create a vector of doubles, reserve place for the divisors of 2400
	//fill this places with random numbers from 0 to 2400
	//sort them in ascending order

	vector<int> v(0);
	int div = 2400;
	for (int i = 1; i < div + 1; i++) {
    if ((div % i) == 0) {
      v.push_back(i);
    }
	}

	for (unsigned int i = 0; i < v.size(); i++) {
    cout << v[i] << "|";
	}

	cout << endl << endl;

	vector<double> d(v.size());

	for (unsigned int i = 0; i < d.size(); i++) {
    d[i] = rand() % 2401;
	}

  for (unsigned int i = 0; i < d.size(); i++) {
    cout << d[i] << "|";
  }

  cout << endl << endl;

  for (unsigned int i = 0; i < d.size(); i++) {
    cout << d[i] << "|";
  }

  sort(d.begin(), d.end(), ascending_vector);

  for (unsigned int i = 0; i < d.size(); i++) {
    cout << d[i] << "|";
  }

  cout << endl;

  return 0;
}
