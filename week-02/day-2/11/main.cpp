#include <iostream>
#include <string>

using namespace std;

string enda (string e){
    return e+"a";
}

int main() {
  string k = "kuty";
  // write a function that gets a string as an input
  // and appends an 'a' character to its end

  cout << enda(k);

  return 0;
}
