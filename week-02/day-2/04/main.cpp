#include <iostream>
#include <string>

using namespace std;

int main() {
	int d[] = {1, 2, 3, 8, 5, 6};
	// change 8 to 4, than print all the elements of the array

	for(int i=0; i<sizeof(d)/sizeof(int); i++){
        if(d[i]==8){
            d[i]=4;
        }
        cout << d[i] << endl;
	}

  return 0;
}
