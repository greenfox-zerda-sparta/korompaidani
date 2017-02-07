#include "Singleton.hpp"
const int MAP_SIZE(30);

Singleton* Singleton::mInstance = NULL;

Singleton::Singleton() {
}

Singleton* Singleton::getInstance() {
  if (mInstance == NULL) {
    mInstance = new Singleton;
  }
  return mInstance;
}

