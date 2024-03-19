void RPG::attack(RPG *opponent) {
    int damage = strength - opponent->getDefense();
    int new_health = opponent->getHealth() - damage;
    opponent->updateHealth(new_health);
}

