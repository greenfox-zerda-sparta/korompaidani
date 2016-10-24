#include <iostream>

using namespace std;

int main()
{
	float w = 24;
	int out = 0;
	// if w is even increment out by one
	float in;
	int counter=0;
    cout<<"If you type a number which is bigger than 24 the result will be incremented.\n";
    do{
        cout<<"Please type  any int num: ";
        cin>>in;
        if(in>w){
            out++;
        }
        counter++;
        cout<<"The result is: "<<out<<endl;
	}while(counter<3);


    return 0;
}
