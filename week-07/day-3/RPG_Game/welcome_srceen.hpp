#pragma once
#include "game-engine-2.hpp"

class welcome_srceen {
private:
  std::string welcome_srceen_path;
  bool key_was_pressed;
public:
  welcome_srceen();
  ~welcome_srceen();
  std::string get_welcome_srceen_path();
  void appear(GameContext&);
};

