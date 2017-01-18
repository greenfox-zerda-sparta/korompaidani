#include <iostream>
#include <string>
#include <map>
#include <algorithm> 

using namespace std;

// write a function that takes a string and returns a map
// the map should have the letters of the string as keys and 
// it should have integers as values that represents how many times the
// letter appeared int the string

map<char, int> freq_of_letter(string word) {
  map<char, int> temp;
  for (int i = 0; i < word.size(); i++) {
    if (temp.find(word[i]) != temp.end()) {
      temp[word[i]]++;
    }
    else {
      temp[word[i]] = 1;
    }
  }
  return temp;
}

int main4() {
  map<char, int> m = freq_of_letter("majom");
  
  for (map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
    cout << it->first << " " << it->second << endl;
  }

  system("pause");

  return 0;
}