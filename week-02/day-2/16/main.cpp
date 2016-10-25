#include <iostream>
using namespace std;

int main(){
	int m[3][3]= {{1,2,3},{4,5,6},{7,8,9}};
///This is an array of arrays. Print it out as a 3x3 matrix. Using each inner array as

/*
	cout << m[0][0] << '|' << m[0][1] << '|' << m[0][2] << '|' << endl;
	cout << m[1][0] << '|' << m[1][1] << '|' << m[1][2] << '|' << endl;
	cout << m[2][0] << '|' << m[2][1] << '|' << m[2][2] << '|' << endl << endl;
*/

    int length = sizeof(m) / sizeof(int);


    for (int i=0; i < length/3; i++){
        for (int j=0; j < length/3; j++){
            cout << m[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << endl;

///a.) a row

    for (int i=0; i < length/3; i++){
        for (int j=0; j < length/3; j++){
            cout << m[i][j];
        }
    }
    cout << endl << endl;

///b.) a column
    for (int i=0; i < length/3; i++){
            for (int j=0; j < length/3; j++){
                cout << m[i][j] << '\n';
            }
    }

///c.) all in one line separated by the character '|'

    for (int i=0; i < length/3; i++){
        for (int j=0; j < length/3; j++){
            cout << m[i][j] << '|';
        }
    }
    cout << endl << endl;

///d.) all in one column
    for (int i=0; i < length/3; i++){
            for (int j=0; j < length/3; j++){
                cout << m[i][j] << '\n';
            }
    }




	return 0;
}
