#include <iostream>
#include <string>

using namespace std;

int main()
{
	string x = "cheese";
	// Tell if the x has even or odd number of
	// characters with a True for even and
	// false False output otherwise

	bool out;

    if(x.length()%2==0){
        out=true;
    }else{
        out=false;
    }
    cout<<out;

    return 0;
}
