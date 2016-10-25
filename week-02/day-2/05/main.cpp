#include <iostream>
#include <string>

using namespace std;

int main() {
	int e[] = {1, 2, 3, 4, 5};
	// increment the 3rd element, than print all the elements of the array

	for(int i=0; i<sizeof(e)/sizeof(int); i++){
        if(i==2){
            e[i]+=1;
        }
        cout << e[i] << endl;
	}

/*====================with while=======================*/

	int j=0;
	while(j<sizeof(e)/sizeof(int)){
        if(j==2){
            e[j]+=1;
        }
        cout << e[j] << endl;
        j++;

	}

  return 0;
}
