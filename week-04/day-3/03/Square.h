#ifndef SQUARE_H
#define SQUARE_H
using namespace std;

class Square : public Shape
{
  public:
    Square();
    virtual string* getName();
  private:
};

#endif // SQUARE_H
