#include <iostream>

using namespace std;

int main()
{
	int z = 21;
	// if z is between 10 and 20 print 'Sweet!'
	// if less than 10 print 'More!',
	// if more than 20 print 'Less!'
	if(z>10&&z<20){
        cout<<"Sweet!";
	}
	if(z<10){
        cout<<"More!";
	}
	if(z>20){
        cout<<"Less!";
	}

    return 0;
}
