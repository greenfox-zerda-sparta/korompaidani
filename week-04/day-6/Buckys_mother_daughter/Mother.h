#ifndef MOTHER_H
#define MOTHER_H

using namespace std;

class Mother {
  public:
    int publicv;
    Mother();
    void sayName();
    void mother_priv_setter(int input);
    virtual void mother_prot_setter(int input);
    void get_mother_priv_n_prot();
  protected:
    int protectedv;
  private:
    int privatev;
};

#endif // MOTHER_H
