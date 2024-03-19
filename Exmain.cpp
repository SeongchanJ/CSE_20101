#include <iostream>
#include <string>

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
        this->defense = defense;
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

    string getSkill(int index) {
        return skills[index];
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
    RPG customRPG("CustomNPC", 150, 15, 20, "mage");

    RPG *players[2] = {&defaultRPG, &customRPG};

    for (int i = 0; i < 2; ++i) {
        cout << "\nPlayer " << i + 1 << " stats:" << endl;
        cout << "Name: " << players[i]->getName() << endl;
        cout << "Health: " << players[i]->getHealth() << endl;
        cout << "Strength: " << players[i]->getStrength() << endl;
        cout << "Defense: " << players[i]->getDefense() << endl;
        cout << "Type: " << players[i]->getType() << endl;

        // Test isAlive and updateHealth
        cout << "Is Player " << i + 1 << " alive? " << (players[i]->isAlive() ? "Yes" : "No") << endl;

        int skillChoice;

        do {
            cout << "\nPlayer " << i + 1 << ", choose a skill (0 or 1): ";
            cin >> skillChoice;

            if (skillChoice != 0 && skillChoice != 1) {
                cout << "Invalid input! Please enter 0 or 1." << endl;
            }
        } while (skillChoice != 0 && skillChoice != 1);

        cout << "Player " << i + 1 << " chose skill: " << players[i]->getSkill(skillChoice) << endl;
    }

    return 0;
}

