#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

void finder_filler(string missword, char input, string&display_word, int&counter);
void linefiller(string&display_word);
void user_deciph(string missword, string userword, int&counter, int rounds);
void superuser_mode(string&missword, char decision);

int main()
{
  string missword = "ORGANIC";
  char input;
  char decision;
  int counter = 0;
  string display_word = missword;
  linefiller(display_word);
  const int rounds = 5;
  string userword;

  //superuser_mode(missword, decision);

  do {
    cout << "Please enter one letter: ";
    cin >> input;
    cout << endl << endl;
    finder_filler(missword, toupper(input), display_word, counter);
    cout << display_word << endl << endl;
    cout << "You have only " << rounds - counter << " chance my friend." << endl << endl;
    user_deciph(missword, userword, counter, rounds);

  }
  while(counter != 5);
  return 0;
}
void finder_filler(string missword, char input, string&display_word, int&counter) {
  for(int i = 0; i < missword.length(); i++) {
    if(display_word[i] != '_') {
        display_word[i] = display_word[i];
    }
    else if(missword[i] == input) {
        display_word[i] = input;
    }
    else if(missword[i] == ' ') {
        display_word[i] = ' ';
    }
    else {
        display_word[i] = '_';
    }
  }
  counter++;
}

void linefiller(string&display_word) {
  for(int i = 0; i < display_word.length(); i++) {
    display_word[i] = '_';
  }
}

void user_deciph(string missword, string userword, int&counter, int rounds) {
  cout << "If you know the answer type it, or enter \"NO\": ";
  cin >> userword;
  if(userword == "NO") {
    cout << "\nLet's go, maybe in next round!\n";
  }
  else if(userword != missword) {
    cout << "\nIt's wrong answer! Maybe in next round\n";
  }
  else if(userword == missword) {
    system("color B8");
    cout << "\nHey you have won! Congrat!\n";
    counter = rounds;
  }
}

void superuser_mode(string&missword, char decision) {
  string buffer;
  cout << "Would you like to enter into superuser mode? <y/n>\n";
  cin >> decision;
  if(decision == 'y') {
    cout << "\nPlease enter your idea.\nIt can be only one word or sentence.";
    cin >> buffer;
    //cout << "buffer length is: " << buffer.length();
    for(int i = 0; i < buffer.length(); i++) {
      missword[i] = toupper(buffer[i]);
    }
    missword[buffer.length()] = '\0';
    cout << "\nThanks!\n";
  }
}
