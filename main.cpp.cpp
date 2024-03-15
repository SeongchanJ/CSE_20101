#include <iostream>
#include "RPG.h"

using namespace std;

int main() {
    RPG defaultRPG;

    RPG customRPG("CustomNPC", 150, 15, 20, "mage");

    cout << "Default RPG stats:" << endl;
    cout << "Name: " << defaultRPG.getName() << endl;
    cout << "Health: " << defaultRPG.getHealth() << endl;
    cout << "Strength: " << defaultRPG.getStrength() << endl;
    cout << "Defense: " << defaultRPG.getDefense() << endl;
    cout << "Type: " << defaultRPG.getType() << endl;

    cout << "\nCustom RPG stats:" << endl;
    cout << "Name: " << customRPG.getName() << endl;
    cout << "Health: " << customRPG.getHealth() << endl;
    cout << "Strength: " << customRPG.getStrength() << endl;
    cout << "Defense: " << customRPG.getDefense() << endl;
    cout << "Type: " << customRPG.getType() << endl;

    return 0;
}

