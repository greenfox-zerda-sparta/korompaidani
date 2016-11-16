#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

string stream_to_string(string mystr) {
  ifstream myfile(mystr.c_str());
  stringstream ss;
  ss << myfile.rdbuf();
  string myString = ss.str();
  myfile.close();
  return myString;
}

bool cp_file_content_to_file(string from_file, string to_file) {
  ofstream output(to_file.c_str());
  output << read_file(from_file);

  if (stream_to_string(from_file) == stream_to_string(to_file)) {
    return true;
  }
  else {
    return false;
  }
}

int main() {

  string from_file = "sample.txt";
  string to_file = "to.txt";

  cout << cp_file_content_to_file(from_file, to_file);



  // Write a function that copies a file to an other
  // It should take the filenames as parameters
  // It should return a boolean that shows if the copy was successful

  return 0;
}
