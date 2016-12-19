#include "stdafx.h"
#include "WordToolbox.hpp"

WordToolbox::WordToolbox(std::string in_word) {
  this->stringHeld = in_word;
}

WordToolbox::~WordToolbox() {
}

void WordToolbox::set_stringHeld(std::string in_word) {
  this->stringHeld = in_word;
}

std::string WordToolbox::get_stringHeld() {
  return this->stringHeld;
}

bool WordToolbox::isAnAnagram(std::string stringToCheck) {
  std::string sortedWord = stringToCheck;
  std::string sortedWord2 = stringHeld;

  for (int i = 0; i < sortedWord.length(); ++i) {
    sortedWord[i] = toupper(sortedWord[i]);
  }
  for (int i = 0; i < sortedWord2.length(); ++i) {
    sortedWord2[i] = toupper(sortedWord2[i]);
  }

  std::sort(sortedWord.begin(), sortedWord.end());
  std::sort(sortedWord2.begin(), sortedWord2.end());
   
  if (sortedWord.compare(sortedWord2) == 0) {
    return true;
  }
  return false;
}

int WordToolbox::countHowMany(char charToFind) {
  std::string sortedWord = stringHeld;
  for (int i = 0; i < sortedWord.length(); ++i) {
    sortedWord[i] = toupper(sortedWord[i]);
  }
  charToFind = toupper(charToFind);

  int count = 0;

  for (int i = 0; i < sortedWord.length(); i++) {
    if (charToFind == sortedWord[i]) {
      count++;
    }
  }
  return count;
}
