#include <iostream>
#include <string.h>

using namespace std;

int charcheck(char letter, string word, int length);

int main() {
  string word = "makkoshotyka-also";
  char letter = 'o';
  // Write a function that takes a string and a character, and counts how many
  // times the character occures in the string and it should return a number
  int length = word.length();

  cout << charcheck(letter, word, length);

  return 0;
}

int charcheck(char letter, string word, int length){
    int counter=0;
    for (int i=0; i < length; i++){
        if (word[i] == letter){
            counter++;
        }
    }
    return counter;
}
