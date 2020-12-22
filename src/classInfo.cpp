//the logic of class "ClassInfo"
#include "classInfo.hpp"
#include <iostream>
#include <string>

// Constructor
// :: indicates that this is refering to the Class "classInfo" constructor/functions
ClassInfo::ClassInfo(string toBeNamed, string hitdice) {
    name = toBeNamed;
    hit_dice = hitdice;
}
