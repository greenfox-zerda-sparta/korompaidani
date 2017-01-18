#include <iostream>
#include <string>
#include <map>
#include <algorithm> 
#include <iterator>

using namespace std;

void print_elements(int i) {
  cout << i << endl;
}

int main7() {
  map<string, string> m;

  m["aladar"] = "geza";
  m["jeno"] = "lacko";
  m["jozsi"] = "sanyi";

  for (map<string, string>::iterator it = m.begin(); it != m.end(); it++) {
    cout << it->first << " " << it->second << endl;
  }

  map<int, int> coord1;
  map<int, int> coord2;

  coord1[4] = 3;
  coord2[4] = 3;

  if (coord1 == coord2) {
    cout << "same" << endl;
  }
  else {
    cout << "NOT same" << endl;
  }

  system("pause");

  return 0;
}