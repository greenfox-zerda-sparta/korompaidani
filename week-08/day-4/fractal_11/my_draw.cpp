#include "my_draw.hpp"

my_draw::~my_draw() {
}

int my_draw::fibonacci(int n) {
  if ((0 == n) || (1 == n)) {
    return n;
  }
  else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}