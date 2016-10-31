#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main()
{
   /* int input;
    cout<<"Please enter a number between 1 and 3999: ";
    cin>>input;

    char i='I';
    char v='V';
    char x='X';
    char l='L';
    char c='C';
    char d='D';
    char m='M';
    int counter=0;
*/

    string rom="";

    const int one=3;        ///I
    const int quint=5;      ///V
    const int dec=11;       ///X
    const int qdec=quint;   ///V
    const int cent=dec;     ///C
    const int qcent=quint;  ///L
    const int mil=dec;      ///M
    const int qmil=quint;   ///D



int term=0;

        for(int o=0; o<=one+1; o++)
        {
            rom+="I";
            if(o==one+1&&term==0)
            {
                rom="V";
                o=0;
                term++;
                if(term==2)
                {
                    o=one;
                }
            }
        cout<<rom<<endl;
        }

    return 0;
}

/*1 11 111 15 51 511 5111*/
