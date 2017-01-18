#include <iostream>
#include <string>

using namespace std:

string* char_star_array_to_string_array(char** input, int size) {
  string* temp_array = new string[size];
  for (int i = 0; i < size; i++) {
    temp_array[i] = input[i];
  }
  return temp_array;
}

int main() { 

  char* arr_char[2];
  arr_char[0] = "apple";
  arr_char[1] = "banana";

  cout << arr_char[0] << endl;
  cout << arr_char[1] << endl;
  string* str = char_star_array_to_string_array(arr_char, 2);
//string* str = char_star_array_to_string_array(*&arr_char, 2);  and this line is also works
  cout << str[0] << endl;
  cout << str[1] << endl;

return 0;
}