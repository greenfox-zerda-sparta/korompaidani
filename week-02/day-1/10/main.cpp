#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int j1 = 10;
	int j2 = 3;
	// tell if j1 is higher than j2 squared and smaller than j2 cubed

	double j2sq = j2*j2;
	double j2cb = j2sq*j2;

	cout<<"this is squared of "<<j2<<" is:"<<j2sq<<endl;
	cout<<"this is cubed of "<<j2<<" is:"<<j2cb<<endl;

	if(j1>j2sq&&j1<j2cb){
        cout<<"j1 is higher than j2 squared and smaller than j2 cubed";
	}


    return 0;
}
