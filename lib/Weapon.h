#ifndef HEROES_5_WEAPON_H
#define HEROES_5_WEAPON_H

#include <string>

using namespace std;

class Weapon {
private:
    string _name;
    int _type;
    int _damage;

public:
    Weapon(string name, int type, int damage)
        : _name(name), _type(type), _damage(damage) {}

    string getName() {
        return _name;
    }

    int getType() {
        return _type;
    }

    int getDamage() {
        return _damage;
    }
};


#endif //HEROES_5_WEAPON_H
