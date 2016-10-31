#include <iostream>
using namespace std;


int main(int argc, char** argv){
    int a = 42; // An integer type variable called "a" that stores 42 as a value
    int *address_of_a = &a; // A pointer to integer type variable called "address_of_a" that stores the memory adress of the variable called "a"
    cout << "Value of variable \"a\": " << a << endl; // Prints: Value of variable "a": 42
    cout << "Value of pointer to variable \"a\": " << address_of_a << endl; // Prints: Value of pointer to variable "a": 0x7fff37922684
    cout << "Value of variable referenced by pointer \"address_of_a\": " << *address_of_a << endl; // Prints: Value of variable referenced by pointer "address_of_a": 42
    cout << "Address of variable \'a\': " << &a << endl; // Prints: Address of variable 'a': 0x7fff37922684
    return 0;
}
