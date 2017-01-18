
#define CATCH_CONFIG_MAIN

#include "Catch.h"

#include "sudoku.h"



TEST_CASE("Sudoku vector is empty") {

  std::vector<int> v;

  REQUIRE_FALSE(sudoku_is_valid(v));

}



TEST_CASE("If sudoku 1x1 is valid") {

  std::vector<int> v = { 1 };

  REQUIRE(sudoku_is_valid(v));

}



TEST_CASE("Sudoku is not valid with 8 long (not square number) vector") {

  std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8 };

  REQUIRE_FALSE(sudoku_is_valid(v));

}



TEST_CASE("Sudoku is valid with a square number (e.g. 4) long vector") {

  std::vector<int> v = { 1, 2, 3, 4 };

  REQUIRE(sudoku_is_valid(v));

}



TEST_CASE("Sudoku is invalid if containing number is higher than size") {

  std::vector<int> v1 = { 4 };

  std::vector<int> v2 = { 1, 8, 3, 4 };

  REQUIRE_FALSE(sudoku_is_valid(v1));

  REQUIRE_FALSE(sudoku_is_valid(v2));

}



TEST_CASE("Sudoku is invalid if vector contains number lower than 1") {

  std::vector<int> v = { 0 };

  REQUIRE_FALSE(sudoku_is_valid(v));

}



TEST_CASE("Sudoku is valid if vector doesn't contain equal numbers") {

  std::vector<int> v = { 1, 1, 3, 4 };

  REQUIRE_FALSE(sudoku_is_valid(v));

}