#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ofstream my_file;
  my_file.open("first-exercise.txt");

  my_file << "Daniel Korompai\n";
  my_file.close();
  // Open a file called "first-exercise.txt"
  // Write your name in it as a single line

  return 0;
}
