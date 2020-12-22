//.hh files or "headers" are the instantiation of a class --> don't contain the logic of the class
//.cpp files contain the logic of the class
#ifndef CLASSINFO_H_
#define CLASSINFO_H_

#include <string>
#include <iostream>

using namespace std;

//Declare class info class
class ClassInfo {
    public:
    //constructor --> same name as class
    ClassInfo(string toBeNamed, string hitdice);

    string name;
    string hit_dice;
};

#endif