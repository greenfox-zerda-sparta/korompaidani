#pragma once
#include "level_builder.hpp"

class square_level : public level_builder{
private:
  int frame_size;
  int shift;
public:
  square_level();
  ~square_level();
  void square_drawer();
};

