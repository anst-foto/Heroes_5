#ifndef HEROES_5_HERO_H
#define HEROES_5_HERO_H

#include <string>

#include "Weapon.h"

using namespace std;

class Hero {
private:
    string _name;
    int _health;
    int _damage;
    int _type;
    Weapon* _weapon;

public:
    Hero(string name, int health, int damage, int type)
        : _name(name), _type(type) {

        _weapon = nullptr;

        if (health < 0) {
            _health = 0;
        } else {
            _health = health;
        }

        if (damage < 0) {
            _damage = 0;
        } else {
            _damage = damage;
        }
    }

    string getName(){
        return _name;
    }

    int getHealth() {
        return _health;
    }
    void setHealth(int health) {
        if (health <= 0) {
            _health = 0;
        } else {
            _health = health;
        }
    }

    int getDamage() {
        return _damage;
    }

    int getType() {
        return _type;
    }

    Weapon *getWeapon() {
        return _weapon;
    }
    bool setWeapon(Weapon *weapon) {
        if (weapon->getType() == _type) {
            _weapon = weapon;
            return true;
        }
        return false;
    }

    bool isDead() {
        return _health == 0;
    }
};


#endif //HEROES_5_HERO_H
