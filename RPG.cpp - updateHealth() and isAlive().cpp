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

    void updateHealth(int new_health) {
        health = new_health;
    }
    bool isAlive() {
        return health > 0;
    }
};

