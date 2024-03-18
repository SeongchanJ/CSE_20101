#include <iostream>
#include <string>
#include <cmath> // Include the cmath library for abs() function

using namespace std;

class RPG {
private:
    string name;
    int health;
    int strength;
    int defense;
    string type;
    string skills[2];

public:
    RPG() {
        name = "NPC";
        health = 100;
        strength = 10;
        defense = 10;
        type = "warrior";
        skills[0] = "slash";
        skills[1] = "parry";
    }

    RPG(string name, int health, int strength, int defense, string type) {
        this->name = name;
        this->health = health;
        this->strength = strength;
        this->defense = abs(defense); // Ensure defense is non-negative
        this->type = type;
        setSkills();
    }

    void setSkills() {
        if (type == "mage") {
            skills[0] = "fire";
            skills[1] = "thunder";
        } else if (type == "thief") {
            skills[0] = "pilfer";
            skills[1] = "jab";
        } else if (type == "archer") {
            skills[0] = "parry";
            skills[1] = "crossbow_attack";
        } else {
            skills[0] = "slash";
            skills[1] = "parry";
        }
    }

    string getName() {
        return name;
    }

    int getHealth() {
        return health;
    }

    int getStrength() {
        return strength;
    }

    int getDefense() {
        return defense;
    }

    string getType() {
        return type;
    }

    void updateHealth(int new_health) {
        health = new_health;
    }

    bool isAlive() {
        return health > 0;
    }
};

int main() {
    // Create an RPG object using the default constructor
    RPG defaultRPG;

    // Create an RPG object using the overloaded constructor
    RPG customRPG("CustomNPC", 150, 15, -20, "mage"); // Negative defense value

    // Test accessor functions
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

    // Test isAlive and updateHealth
    cout << "\nIs default RPG alive? " << (defaultRPG.isAlive() ? "Yes" : "No") << endl;
    cout << "Is custom RPG alive? " << (customRPG.isAlive() ? "Yes" : "No") << endl;

    return 0;
}

