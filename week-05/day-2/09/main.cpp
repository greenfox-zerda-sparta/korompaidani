#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string read_file(string filename) {
  ifstream input;
  string line;
  string content;
  input.open(filename.c_str());
  if (!input.is_open()) {
    cout << "Cannot open " << filename << '!';
    return "file open error";
  }
  else {
    while (getline(input, line)) {
      content += line + '\n';
    }
    input.close();
    return content;
  }
}

void decrypter(string encrypted) {
  for (int i = 0; i < encrypted.length(); i++) {
    if (i % 2 == 0) {
      cout << encrypted[i];
    }
  }

}

int main() {

  string file1 = "encrypted.txt";

  decrypter(read_file(file1));

  // Create a program that decrypts the file called "duplicated-chars.txt",
  // and pritns the decrypred text to the terminal window.

  return 0;
}
