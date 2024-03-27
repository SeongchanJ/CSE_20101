#include <iostream>
#include <string>
#include <cstdlib> // for abs() function

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
        this->defense = abs(defense);
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

    void printAction(string skill, RPG opponent) {
        printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str());
    }

    string getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

    int getStrength() const {
        return strength;
    }

    int getDefense() const {
        return defense;
    }

    string getType() const {
        return type;
    }

    void updateHealth(int new_health) {
        health = new_health;
    }

    bool isAlive() const {
        return health > 0;
    }

    void attack(RPG* opponent);

    void useSkill(RPG* opponent);
};

void RPG::attack(RPG* opponent) {
    int damage = this->strength - abs(opponent->getDefense());
    int new_health = opponent->getHealth() - damage;
    opponent->updateHealth(new_health);
}

void RPG::useSkill(RPG* opponent) {
    for (int i = 0; i < 2; ++i) {
        cout << "Skill " << i << ": " << skills[i] << endl;
    }

    cout << "Choose a skill to use: Enter 0 or 1\n";

    int chosen_skill_index;
    cin >> chosen_skill_index;

    string chosen_skill = skills[chosen_skill_index];

    printAction(chosen_skill, *opponent);
    attack(opponent);
}

void displayStats(RPG player1, RPG player2) {
    cout << player1.getName() << " health: " << player1.getHealth() << " " << player2.getName() << " health: " << player2.getHealth() << endl;
}

void displayEnd(RPG player1, RPG player2) {
    if (player1.isAlive()) {
        cout << player1.getName() << " defeated " << player2.getName() << "! Good game!" << endl;
    } else {
        cout << player2.getName() << " defeated " << player1.getName() << "! Good game!" << endl;
    }
}

void gameLoop(RPG* player1, RPG* player2) {
    while (player1->isAlive() && player2->isAlive()) {
        cout << player1->getName() << "'s turn!" << endl;
        player1->useSkill(player2); // Player 1 uses skill on player 2

        displayStats(*player1, *player2); // Display updated stats

        cout << "--------------------------------\n";

        cout << player2->getName() << "'s turn!" << endl;
        player2->useSkill(player1); // Player 2 uses skill on player 1

        displayStats(*player1, *player2); // Display updated stats again

        cout << "--------------------------------\n";
    }
}

int main() {
    RPG p1 = RPG("Wiz", 70, 45, 15, "mage");
    RPG p2 = RPG();

    gameLoop(&p1, &p2);
    displayEnd(p1, p2);

    return 0;
}


