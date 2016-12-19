#include "stdafx.h"
#define CATCH_CONFIG_MAIN
#include "C:\Users\korom\OneDrive\Programming\TEST\catch.hpp"
#include "WordToolbox.hpp"

TEST_CASE("setter and getter test") {
  WordToolbox wtb("Rogue One");
  
  CHECK(wtb.get_stringHeld() == "Rogue One");
  CHECK(wtb.isAnAnagram("Rugoe ONe") == true);
  CHECK(wtb.countHowMany('o') == 2); 
}

TEST_CASE("Second test") {
  WordToolbox wSource("Tarzan's toenails");
  std::cout << "countHowMany(\"a\")=" << wSource.countHowMany('a') << std::endl; // countHowMany("a")=3
  std::cout << "countHowMany(\"T\")=" << wSource.countHowMany('T') << std::endl; // countHowMany("T")=2
  std::cout << "countHowMany(\"t\")=" << wSource.countHowMany('t') << std::endl; // countHowMany("t")=2
  std::cout << "countHowMany(\"x\")=" << wSource.countHowMany('x') << std::endl; // countHowMany("x")=0
  std::cout << "countHowMany(\" \")=" << wSource.countHowMany(' ') << std::endl; // countHowMany(" ")=1
  CHECK(wSource.countHowMany('a') == 2);
}