#include <iostream>
using namespace std;

union ptr{
	int* asInt;
	char* asChar;

};


int main() {
	char* a = new char[256];
	char* b = a;
	cout << a-b << endl << (++b)-a << endl;
	--b;
	int* c=(int*)a;
	c++;

	cout << c-((int*)a) << endl;
	cout << ((char*)c)-a << endl;
	
	ptr p;
	p.asChar = a;
	ptr q;
	q.asChar = a;
	q.asInt++;
	cout << q.asInt - p.asInt << "  " << q.asChar - p.asChar << endl;

	return 0;
}
