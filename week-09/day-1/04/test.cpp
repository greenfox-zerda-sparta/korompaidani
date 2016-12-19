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
  WordToolbox wtb("Rogue One");

  CHECK(wtb.get_stringHeld() == "Rogue One");
  CHECK(wtb.isAnAnagram("Rugoe ONe") == true);
  CHECK(wtb.countHowMany('o') == 2);
}