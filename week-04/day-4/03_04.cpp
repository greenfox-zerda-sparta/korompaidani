
#include <iostream>
#include <string>
using namespace std;

class ParentClass {
  public:
    ParentClass();
    string getString();
    virtual string getVirtualString();
    virtual ~ParentClass();
  private:
    string* mParentString;
};

ParentClass::ParentClass() {
  mParentString = new string("default parent vaule");
};

string ParentClass::getString() {
  return string(*mParentString);
};

string ParentClass::getVirtualString() {
  return string(*mParentString);
};

ParentClass::~ParentClass() {
  delete this->mParentString;
};

class ChildClass : public ParentClass {
  public:
    ChildClass();
    string getString();
    virtual string getVirtualString();
    virtual ~ChildClass();
  private:
    string* mChildString;
};

ChildClass::ChildClass() {
  mChildString = new string("child value");
};

string ChildClass::getString() {
  return string(*mChildString);
};

string ChildClass::getVirtualString() {
  return string(*mChildString);
};

ChildClass::~ChildClass() {
  delete this->mChildString;
}


// Create a class called ParentClass. It should have two public functions. Both return a string. One virtual, the other not.
// Each should return a unique string.
// Create a ChildClass which inherits from the ParentClass publicly.
// This should override both functions. The virtual and the nonvirtual one both.
// These should return unique string again.
//
// Create a main() function. In this function, create a ParentClass* pointer and instanciate a ChildClass member for that pointer.
// Hint: This should look something like this: ParentClass* a = new ChildClass();
// Print out the result of both functions on this a ponter.
// Print out the result of both functions if You first cast pointer a to be interpreted as of type ChildClass*
//

int main() {
  ParentClass pc2;
  cout << pc2.getString() << "\t || \t" << pc2.getVirtualString() << endl;

  ParentClass* pc1 = new ChildClass();
  cout << pc1->getString() << "\t || \t" << pc1->getVirtualString() << endl;
  cout << ((ChildClass*)pc1)->getString() << " " << ((ChildClass*)pc1)->getVirtualString();

  return 0;
}
