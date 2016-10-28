#include <iostream>
#include <string.h>
using namespace std;

void alphabetSlicer(char beginner, char arr[6]);

//Implement the above declared function to return the next 5 characters in the english alphabet
//after the character 'beginner' in an array of characters.
//The last chracter of the array should be '\0'.
//If there are less then 5 characters left after 'beginner' start from the beginning.
//So, alphabetSlicer(y) should return {'z','a','b','c','d','\0'}

int main(int argc, char** argv){
	char arr[6];

	cout << arr << endl;
	alphabetSlicer('d', arr);
	cout << arr << endl;
	alphabetSlicer('w', arr);
	cout << arr << endl;

	return 0;
}

void alphabetSlicer(char beginner, char arr[6]){
  string entalph = "abcdefghijklmnopqrstuvwxyz";
  int indentalph = 0;
  char goodlet;
  char a = 'a';
  int beg = 0;
  string buffer[26];
  for (int i=0; i < entalph.length(); i++){
    if (beginner == entalph [i]){
      goodlet = entalph[i];
      indentalph = i;
    }
  }
  for (int i=0; i < indentalph; i++){
      a++;
    }
  if (indentalph <= 20){
    for(int i=0; i< 6; i++){
      arr[i] = a;
      a++;
    }
  }
  else {
    for(int i=0; i < 26 - indentalph; i++){
      arr[i] = a;
      a++;
      beg = i;
    }
    a = 'a';
    for(int i=beg + 1; i < 6 - 26 - indentalph; i++){
      arr[i] = a;
      a++;
    }
  }
}





