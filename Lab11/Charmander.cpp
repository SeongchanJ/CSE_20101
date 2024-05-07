#include <iostream>
#include <stdio.h>
#include "Charmander.h"

Charmander::Charmander() : Pokemon("unidentified", 0, 0, 0, {"Fire"}) {
  skills.push_back("Growl");
  skills.push_back("Scratch");
  cout << "Default Constructor (Charmander)\n";
}

Charmander::Charmander(string name, int hp, int att, int def, vector<string> t, vector<string> s) :
   Pokemon(name, hp, att, def, t), skills(s)  {
   
      cout << "Overloaded Constructor (Charmandor)\n";
}
/**
 * @brief says what a charmander says
 *
 */

void Charmander::speak() {
  cout << "Charmander-char\n";
}

/**
 * @brief calls printStats from the parent class (Pokemon) and appends the skills used for Charmander
 *
 */

void Charmander::printStats() {
  Pokemon::printStats();
  cout << "Skills: ";
  for (int i = 0; i < skills.size(); i++){
    cout << skills[i] << "\t";
  }
  cout << endl;
}
