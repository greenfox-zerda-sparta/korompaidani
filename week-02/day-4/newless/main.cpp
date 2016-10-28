#include <iostream>

using namespace std;

int main()
{
    int my_array[] = {1, 2, 3, 4, 5};
    int* pointer = my_array;
    cout << sizeof(my_array) / sizeof(int);
    cout << sizeof(my_array) / sizeof(my_array[0]);
    cout << sizeof(my_array) / sizeof(*my_array); //ahova a my array nulladik eleme mutat
    return 0;
}
