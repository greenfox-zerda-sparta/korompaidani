#include <iostream>
#include <string>

using namespace std;

void ArrayShow(int []);

int main() {
	int b[] = {54, 23, 66, 12};
	// add the second the third

	b[2] = b [1];

    ArrayShow(b);
    cout<<endl<<CHAR_BIT<<endl;
    cout<<sizeof(int)<<endl;
    cout<<sizeof(b)<<endl;

  return 0;
}

void ArrayShow(int arr[]){
    for(int i=0; i<=sizeof(arr)-1; i++){
    cout << arr[i] << endl;


	}
}
