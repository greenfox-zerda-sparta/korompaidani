#include <iostream>
#include <string>
#include <vector>

using namespace std;

void add_vector(vector<vector<int> >& vectorf, vector<int>& vf) {
    vectorf.push_back(vf);
}

int main() {
	//create a vector of vector of integers, yeah a vector that holds vectors of integers
	//the inner vectors have 5 integers, all of them 0
	//the outer vector is holding 5 vector at the begining
	//create a function that will add a new vector of integers to the end of our outer vector

    vector<int> v_inner(5, 0);
    vector<vector<int> > v_outer(5);

    add_vector(v_outer, v_inner);

//    cout << v_outer.size();

 return 0;
}
