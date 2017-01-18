#ifndef TRIANGLE_H
#define TRIANGLE_H
using namespace std;

class Triangle : public Shape
{
  public:
    Triangle();
    virtual string* getName();
  private:
};

#endif // TRIANGLE_H
