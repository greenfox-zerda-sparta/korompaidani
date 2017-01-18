#ifndef STACK_H
#define STACK_H
#include "Stack.h"
#include "Intlist.h"

using namespace std;

class Stack : public IntList {
  public:
    Stack(int* array, int size);
		virtual void append(int _a);
		virtual void insert(int _idx, int _a);
		virtual int getFirst();
		virtual int getLast();
		virtual int getLength();
		virtual bool isEmpty();
		int getArrElement(int i);
		int getArray();
  private:
    int mLength;
    int* data;
};

#endif // STACK_H
