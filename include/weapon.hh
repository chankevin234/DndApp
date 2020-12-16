#ifndef WEAPON_H_
#define WEAPON_H_

#include <string>
#include <iostream>

using namespace std;

//Declare weapon class
class Weapon {
    public:
    Weapon(string tobenanmed, string wCategory, string dice, string type);
    
    string name;
    string category;
    string damage_dice;
    string damage_type;
};

#endif