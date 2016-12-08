#pragma once
#include "level_builder.hpp"

class recursive_level : public level_builder {
public:
  recursive_level();
  ~recursive_level();
  virtual void drawer(int, int, int);
};

