#ifndef CLASSINFO_H_
#define CLASSINFO_H_

#include <string>
#include <iostream>

using namespace std;

//Declare class info class
class ClassInfo {
    public:
    ClassInfo(string toBeNamed, string hitdice);

    string name;
    string hit_dice;
};

#endif