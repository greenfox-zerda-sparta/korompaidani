#include <iostream>
#include <string.h>
using namespace std;

// Create a function that prints each word in a string into a new line!
// Create an other function that takes a string and an array of strings as it's input
// and puts each word in the original string into a new element in the array of strings.
// Decide which argument should be a pointer and which shouldn't.
// In the main function, print out each element of the array into a new line!

void wordInliner(string input){
  int space_counter = 0;
  int* space_counter_pointer = &space_counter;
  int space_pos [*space_counter_pointer];
  for (int i = 0; i < input.length(); i++){
    if (input[i] == ' '){
        space_counter++;
        space_pos[i] =  i;
    }
  }
  for (int i = space_pos[0]; i < space_pos[1]-space_pos[0]; i++){
    cout << input[i];
  }

};

int main(int argc, char **argv){
  string sentence = " May the Force be with you bro'!";


  wordInliner(sentence);

  return 0;
}


