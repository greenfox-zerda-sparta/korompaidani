#include <iostream>

#ifdef _SW //if I set this under properties/C++/Preprocessor settings (depends on my IDE) I can see Rogue One, ifndef az n betu megforditja
#define MY_CONST "Rogue One"
#else
#define MY_CONST "Han Solo film"
#endif

int main3() {
  std::cout << MY_CONST << std::endl;

  system("pause");

  return 0;
}


// Create a constant using preprocessor directives.
// Make it so, that depending on the existence of a defined variable
// it's value is different.
// Write a main function that writes it to the console.
// Experiment in Your IDE compiling it with the directive defined or not.
// (This is waht we used -D __DEBUG for example. You can try this and see how it works
// when You compile a Debug version and a Release version.)