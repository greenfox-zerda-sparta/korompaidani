#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include "nem-hagyom-magara-a-gepem.hpp"

using namespace std;

int main3() {
  map<string, int> m;
  m["one"] = 1;
  m["two"] = 2;
  m["three"] = 3;
  m["four"] = 4;
  m["five"] = 5;

  cout << m["one"] << endl;
  // Print all the keys and values of the map

  for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
    cout << it->first << " " << it->second << endl;
  }

  system("pause");
  return 0;
}