#include <string>
#include <iostream>

using namespace std;

struct Computer {
  string name;
  long int cpu_speed_hz;
  long int ram_size;
};

void print(Computer input) {
  cout  << input.name << endl << input.cpu_speed_hz << endl << input.ram_size << endl;
}

int main() {
  Computer computer = {"Macbook", 3.2e9, 8e9};

  // Change the name of the computer to "Macbook Pro" and print all the stats
  computer.name = "Macbook Pro";
  cout << computer.name << endl << computer.cpu_speed_hz << endl << computer.ram_size << endl;

  print(computer);



  return 0;
}
