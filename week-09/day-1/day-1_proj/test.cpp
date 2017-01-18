#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "apple.hpp"

TEST_CASE("apple getter") {
  apple a;

  REQUIRE(a.get_apple() == "apple");
}