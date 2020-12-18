#ifndef DNDBACKEND_H_
#define DNDBACKEND_H_

#include <string>
#include <iostream>
#include <vector>
#include "weapon.hh"
#include "condition.hh"
#include "race.hh"
#include "classInfo.hh"

using namespace std;

//Declare condition class
class DndBackend {
    public:
    DndBackend();

    string getRaceAtIndex(int i);
    string getConditionAtIndex(int i);
    string getClassesAtIndex(int i);
    string getWeaponAtIndex(int i);

    private:
    std::vector<Weapon*> weapons;
    std::vector<Race*> races;
    std::vector<ClassInfo*> classinfos;
    std::vector<Condition*> conditions;
};

//for exporting
extern "C" {
    DndBackend* DndBackend_new(){ return new DndBackend(); }
    string getRace(DndBackend* backend, int index) { return backend->getRaceAtIndex(index); }
    string getCondition(DndBackend* backend, int index) { return backend->getConditionAtIndex(index); }
    string getClasses(DndBackend* backend, int index){ return backend->getClassesAtIndex(index); }
    string getWeapon(DndBackend* backend, int index){ return backend->getWeaponAtIndex(index); }
}

#endif