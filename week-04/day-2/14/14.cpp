#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

int main() {
  Character c1("Gismo", 'm');
  Character c2("Thor", 'p');
  cout << c1.get_name() << "'s defense value is: " << c1.get_defense() << " and the attack value is: " << c1.get_attack() << endl;
  cout << c2.get_name() << "'s defense value is: " << c2.get_defense() << " and the attack value is: " << c2.get_attack() << endl;

  while (c1.get_health() >=  1 && c2.get_health() >= 1) {
    c1.attack_act(c2);
    c2.attack_act(c1);
    cout << c1.get_name() << "'s health is: " << c1.get_health() << endl;
    cout << c2.get_name() << "'s health is: " << c2.get_health() << endl;
  }
  if (c1.get_health() > c2.get_health()) {
    cout << c1.get_name() << " has won!";
  }
  else {
    cout << c2.get_name() << " has won!";
  }
    //RPG Game lite
    //Create a Character class with the following preferences:
    //name
    //character type (player/monster)
    //health point value
    //attack value
    //defense value
    //attacking method which takes a character class and decreases its health
    //value with (current character class attack - input character class defense),
    //if the output is minus, then our health is decreased
    //set the attacking method to have 50% chanse to count our attack value twice,
    //(2xcurrent attack - input defense) before calculating the final health points.

    //create 2 instances of the character class and fill their base stats from their constructor
    //make them attack each other with the attack method from the character class
    //after each round print both the attacker, and the attacked character health
    //make them fight each other until one of them has a health point lower or equal 0
    //print the winner and offer a new game

    //dont forget to use private variables, and get/set methods, and also place out_of_range
    //character class into a seperate file

  return 0;
}
