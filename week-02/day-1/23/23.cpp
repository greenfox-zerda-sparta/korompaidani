#include <iostream>

using namespace std;

int main()
{
	int ad = 6;
	int i;
	// print the numbers till ad from 0
	for(i=0; i<6; i++){
        cout<<i+1<<endl;
	}
	i=0;
    do{
        cout<<i+1<<endl;
        i++;
    }while(i<6);
    i=0;
    while(i<6){
        cout<<i+1<<endl;
        i++;
    }
    return 0;
}
