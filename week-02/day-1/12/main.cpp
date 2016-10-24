#include <iostream>
#include <string>

using namespace std;

int main()
{
	string m = "Apple";
	int contr = 0; //its a control number to check that every step will be processed
	//fill the m variable with its cotnent 4 times
	for (int i=0; i<4;  i++){
        m="Apple";
        contr++;
	}
cout<<"strings content at the and is: "<<m<<"\nand the control number is: "<<contr;
    return 0;
}
