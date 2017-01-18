#ifndef INT_LIST_HPP
#define INT_LIST_HPP
#include "Intlist.h"

using namespace std;

class IntList {
	private:
		int mLength;
	public:
	  IntList();
		virtual void append(int _a);
		virtual void insert(int _idx, int _a);
		virtual int getFirst();
		virtual int getLast();
		virtual int getLength();
		virtual bool isEmpty();
};



#endif
