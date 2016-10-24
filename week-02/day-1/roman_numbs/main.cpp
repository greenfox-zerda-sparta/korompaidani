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
/*
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
    for(int d=0; d<=dec+1; d++){
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


        string decades=rom;

        rom="X";
        term=0;

        cout<<rom<<endl;

    }

*/

char romai[10] = {'I','V','X','L','C','D','M','\\\\\\\\0'};
int arab[8] = {1,5,10,50,100,500,1000};
char *be = "C";
    int a,
    d,
            osszeg,
    hossz,
            hossz2,
    tomb[20];

    hossz = strlen(be);
    hossz2 = strlen(romai);

    for(a = 0; a < hossz; a++)
    {
        for(d = 0; d < hossz2; d++)
        {
        if(romai[d] == be[a])
break;
        }

        if(d >= hossz2)
        {
        // rossz karakter van a számban
        }

        tomb[a] = arab[d];
    }

    for(a = 0; a < hossz; a++)
    {
    if(a >= (hossz-1))
        osszeg += tomb[a];
        else
        {
        if(tomb[a] < tomb[a+1])
            {
            osszeg += tomb[a+1]-tomb[a];
                a++;
            }
            else
            osszeg += tomb[a];
        }
    }


return osszeg;

    return 0;
}
