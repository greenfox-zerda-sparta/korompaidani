// test_1_apple.cpp : Defines the entry point for the console application.
//#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "stdafx.h"
#include <iostream>
#include "Apple.hpp"

using namespace std;

int main5() {
  Apple a;
  cout << a.get_app() << endl;
  return 0;
}

