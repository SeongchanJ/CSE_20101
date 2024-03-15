#ifndef RPG_H
#define RPG_H

#include <string>

using namespace std;

const int SKILL_SIZE = 2;

class RPG {
public:
    RPG();
    RPG(string name, int health, int strength, int defense, string type);

    bool isAlive() const;
    string getName() const;
    int getHealth() const;
    int getDefense() const;
    void setSkills(string skills[SKILL_SIZE]);
    void printAction(string action, RPG target);
    void updateHealth(int damage);
    void attack(RPG* target);
    void useSkill(RPG* target);

private:
    string name;
    int health;
    int strength;
    int defense;
    string type;
    string skills[SKILL_SIZE];
};

#endif
