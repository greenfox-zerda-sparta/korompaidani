#include <iostream>

using namespace std;

int main()
{
	int e = 8;
	// please cube of e's value

	int exp = 3;
	int temp = e;

	for(int i=1; exp>i; i++ ){
        temp=temp*e;
	}
    e=temp;
    cout<<temp;

    return 0;
}
