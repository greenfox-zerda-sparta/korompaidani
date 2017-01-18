#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// Write a simple program that creates secret santa pairs
// It should read names till the character q is typed to the standard output,
// than it should print the names as secret santa pairs like:
// Clair - Mike
// Joe - Ron
// Cloe - Clair
// Ron - Cloe
// Mike - Joe

void print_map(vector<string>& in_vec1, vector<string>& in_vec2) {
  random_shuffle(in_vec1.begin(), in_vec1.end());
  random_shuffle(in_vec2.begin(), in_vec2.end());
  for (unsigned int i = 0; i < in_vec1.size(); i++) {
    for (unsigned int j = i; j < i + 1; j++) {
      if (in_vec1[i] == in_vec2[j]) {
        random_shuffle(in_vec2.begin(), in_vec2.end());
      }
      else {
        cout << in_vec1[i] << " - " << in_vec2[j] << endl;
      }
    }
  }
}

void secret_santa() {
  vector<string> names;
  vector<string> names2;
  string input;
  while (cin >> input) {
    if (input == "q") {
      break;
    }
    names.push_back(input);
    names2.push_back(input);
  }
  print_map(names, names2);
}

int main5() {
  secret_santa();
  system("pause");
  return 0;
}