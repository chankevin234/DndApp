#ifndef DNDBACKEND_H_
#define DNDBACKEND_H_

#include <string>
#include <iostream>
#include <vector>
//calls the header files where classes were instantiated
#include "weapon.hpp"
#include "condition.hpp"
#include "race.hpp"
#include "classInfo.hpp"

using namespace std;

//Declare condition class
class DndBackend {
    public:
    //constructor
    DndBackend();

    //these are all arrays that contain the information --> this is calling from the dndBackend.cpp file where "while loops" are pulling the info into arrays

    private:
    std::vector<Weapon*> weapons;
    std::vector<Race*> races;
    std::vector<ClassInfo*> classinfos;
    std::vector<Condition*> conditions;
};

//for binding
//this section is read by JavaScript only! 
//front end sees these below
extern "C" {
    //DndBackend* is the pointer
    DndBackend* DndBackend_new(){ return new DndBackend(); }
    string getRace(DndBackend* backend, int index) { return backend->getRaceAtIndex(index); }
    string getCondition(DndBackend* backend, int index) { return backend->getConditionAtIndex(index); }
    string getClasses(DndBackend* backend, int index){ return backend->getClassesAtIndex(index); }
    string getWeapon(DndBackend* backend, int index){ return backend->getWeaponAtIndex(index); }
}

#endif