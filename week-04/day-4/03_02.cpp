#include <iostream>
#include <string>
using namespace std;

/// EdgeCase #1.1 - protected variables, and even publics can be overriden as well. See for Yourself.

class ParentClass {
	protected:
		int mVariable;
	public:
		ParentClass();
		void setVariable(int _var);
		int getVariable();
};


ParentClass::ParentClass() {
	this->mVariable = 0;
}

void ParentClass::setVariable(int _var) {
	this->mVariable = _var;
}

int ParentClass::getVariable() {
	return this->mVariable;
}

class ChildClass : public ParentClass {
	protected:
		int mVariable;
	public:
		void setVariable(int _var);
		int getVariable();
		int getParentVariable();
		void setParentVariable(int _var);
};

void ChildClass::setVariable(int _var) {
	this->mVariable = _var;
}

int ChildClass::getVariable() {
	return this->mVariable;
}

int ChildClass::getParentVariable() {
	return this->ParentClass::mVariable;
}

void ChildClass::setParentVariable(int _var) {
	this->ParentClass::mVariable = _var;
}

int main() {
	ParentClass* a = new ChildClass();
	a->setVariable(2);
	((ChildClass*)a)->setVariable(4);
	cout << a->getVariable() << "  " << ((ChildClass*)a)->getVariable() << endl;
	((ChildClass*)a)->setParentVariable(8);
	cout << a->getVariable() << "  " << ((ChildClass*)a)->getVariable() << endl;
	return 0;
}
