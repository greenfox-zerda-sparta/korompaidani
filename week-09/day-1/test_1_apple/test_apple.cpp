#include "stdafx.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "Apple.hpp"

TEST_CASE("apple getter") {
  Apple a;
  REQUIRE(a.get_app() == "apfple");
}