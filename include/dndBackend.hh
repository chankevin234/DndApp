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


    private:
    std::vector<Weapon*> weapons;
    std::vector<Race*> races;
    std::vector<ClassInfo*> classinfos;
    std::vector<Condition*> conditions;
};

//for binding
extern "C" {
    DndBackend* DndBackend_new(){ return new DndBackend(); }
    // add functions here once done backend
}

#endif