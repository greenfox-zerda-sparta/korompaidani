#include <iostream>

using namespace std;

int main()
{
	int ab = 123;
	int credits = 100;
	bool is_bonus = true;
	// if credits are at least 50,
	// and is_bonus is False decrement ab by 2
	// if credits are smaller than 50,
	// and is_bonus is False decrement ab by 1
	// if is_bonus is True ab should remain the same
	if(is_bonus==false){
        if(credits>=50){
            ab=ab-2;
        }
        if(credits<50){
            ab=ab-1;
        }
	}
	if(is_bonus==true){
    cout<<"remain the same"<<endl;
	}
    cout<<ab;
    return 0;
}
