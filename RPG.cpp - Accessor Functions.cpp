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

    void setSkills() { string getName() {
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
};
        skills[0] = "slash";
        skills[1] = "parry";
    }
