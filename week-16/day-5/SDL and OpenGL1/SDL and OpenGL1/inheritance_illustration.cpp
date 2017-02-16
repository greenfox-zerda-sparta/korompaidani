#define CATCH_CONFIG_MAIN
#include <iostream>
using namespace std;

#ifndef CATCH_CONFIG_MAIN

class A {
	protected:
		int a;
		int b;
	public:
		A(int _a, int _b){
			a = _a;
			b = _b;
		}
		int csinalj(){
			return b;
		}
		virtual int mastcsinalj() {
			return a - b;
		}
};

class B : public A {
	public:
		B(int _a, int _b):A(_a,_b){}
		int csinalj() {
			return a;
		}
		virtual int mastcsinalj(){
			return a + b;
		}
};

int main() {

	B b(1,2);
	A* a = &b;
	cout << a->csinalj() << "  " << b.csinalj() << "  "<< a->mastcsinalj() << "  " << b.mastcsinalj() << endl;
	
	return 0;
}
#endif
#ifdef CATCH_CONFIG_MAIN

union ptr {
  int* asInt;
  char* asChar;

};

int main() {

  int arr[2] = { 12, 19 };
  int* pointer = arr;

  cout << pointer << " : " << *pointer << endl;
  pointer += 1;
  cout << pointer << " : " << *pointer << endl;

  char* a = new char[256];
  char* b = a;
  cout << a - b << endl;
  cout << (++b) - a << endl;
  --b;
  int* c = (int*)a;
  c++;

  cout << c - ((int*)a) << endl;
  cout << ((char*)c) - a << endl;

  ptr p;
  p.asChar = a;
  ptr q;
  q.asChar = a;
  q.asInt++;
  cout << q.asInt - p.asInt << "  " << q.asChar - p.asChar << endl;

  return 0;
}

#endif