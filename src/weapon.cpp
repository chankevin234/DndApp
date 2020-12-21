#include "weapon.hh"
#include <iostream>
#include <string>

// Constructor
Weapon::Weapon(string tobenanmed, string wCategory, string dice, string type) {
    name = tobenanmed;
    category = wCategory;
    damage_dice = dice;
    damage_type = type;
}