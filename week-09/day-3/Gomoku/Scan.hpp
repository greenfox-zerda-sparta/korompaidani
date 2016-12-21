#pragma once
#include "ERROR_CODES.hpp"
#include "Map.hpp"
#include "Player.hpp"

class Scan {
private:
public:
  Scan();
  bool horizontal(Map& map);
};

