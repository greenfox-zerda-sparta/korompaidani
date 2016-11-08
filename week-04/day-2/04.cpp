#include <iostream>
#include <string>

using namespace std;

class Student {
  private:
    string name;
    unsigned int age;
  public:
    Student(string name, unsigned int age) {
      this->age = age;
      this->name = name;
    }

    void SetName(string inname) {
      this->name = inname;
    }

    string greet() {
      return "Hello my name is: " + this->name;
    }
};

int main() {
  // Create a method on student that takes a string as an argument and
  // changes it's name property
  Student s1("John", 21);
  cout << endl << s1.greet();
  s1.SetName("Dani");
  cout << endl << s1.greet();

  return 0;
}
