#ifndef DAUGHTER_H
#define DAUGHTER_H
using namespace std;

class Daughter : public Mother {
  public:
    Daughter();
    void sayName();
    void prot_setter(int input);
    virtual void mother_prot_setter(int input);
    ///void priv_setter(int input); of course it doues not work because mother's private isn't available for daughter
};

#endif // DAUGHTER_H
