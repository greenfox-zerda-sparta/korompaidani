#ifndef INT_LIST_HPP
#define INT_LIST_HPP
#include "Intlist.hpp"

class IntList {
	private:
		int mLength;
	public:
		virtual void append(int _a) = 0;
		virtual void insert(int _idx, int _a) = 0;
		virtual int getFirst() = 0;
		virtual int getLast() = 0;
		virtual int getLength() = 0;
		virtual bool isEmpty() = 0;
};



#endif
