#include <iostream>
#include <vector>

#include "./lib/Hero.h"
#include "./lib/Weapon.h"

using namespace std;

void PrintHero(Hero* hero);
void PrintWin(Hero* hero);

int main() {
    // 1 - магический
    // 2 - обычный
    vector<Weapon*> weapons;
    weapons.push_back(new Weapon("Staff", 1, 20));
    weapons.push_back(new Weapon("Sword", 2, 10));

    Hero* mage = new Hero("Mage", 100, 20, 1);
    Hero* barbarian = new Hero("Barbarian", 100, 30, 2);

    PrintHero(mage);
    PrintHero(barbarian);

    bool is_continue = false;
    do {
        int random = 0 + rand() % weapons.size();
        if (!mage->setWeapon(weapons[random])) {
            cout << "bad set weapon" << endl;
        }
        random = 0 + rand() % weapons.size();
        if (!barbarian->setWeapon(weapons[random])) {
            cout << "bad set weapon" << endl;
        }

        mage->Attack(barbarian);
        barbarian->Attack(mage);
        PrintHero(mage);
        PrintHero(barbarian);

        is_continue = !mage->isDead() && !barbarian->isDead();
    } while (is_continue);

    if (mage->isDead() && barbarian->isDead()) {
        cout << "dead heat" << endl;
    } else if (mage->isDead()) {
        PrintWin(barbarian);
    } else if (barbarian->isDead()) {
        PrintWin(mage);
    }

    return 0;
}

void PrintHero(Hero* hero) {
    cout << hero->getName() << endl;
    cout << "Health : " << hero->getHealth() << endl;
    cout << "Damage : " << hero->getDamage() << endl;

    if (hero->getWeapon() != nullptr) {
        cout << "Weapon : " << hero->getWeapon()->getName() << endl;
    }
}

void PrintWin(Hero* hero)  {
    cout << hero->getName() << " is WIN!" << endl;
}