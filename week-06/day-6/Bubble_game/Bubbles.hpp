#ifndef BUBBLES_H
#define BUBBLES_H

#include <vector>

class Bubbles
{
  private:
    void generate_bubble_chars(int bubble_quant);
    int bubble_quant;
    std::vector<char> bubbles;

  public:
    Bubbles(int usernum);
    ~Bubbles();
    void shuffle_bubbles();
    char* get_bubbles();
    int get_bubble_quant();
};

#endif // BUBBLES_H
