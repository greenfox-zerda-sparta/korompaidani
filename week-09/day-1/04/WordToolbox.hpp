#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <locale> 
#include <iostream>

class WordToolbox {
private:
  std::string stringHeld;
public:
  WordToolbox(std::string);
  ~WordToolbox();
  void set_stringHeld(std::string);
  std::string get_stringHeld();
  bool isAnAnagram(std::string);
  int countHowMany(char charToFind);
};

