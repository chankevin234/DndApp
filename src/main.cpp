//main method
// #include adds the libraries or calls the header files
#include <iostream>
#include <fstream>
#include <vector>
#include "weapon.hh"
#include "condition.hh"
#include "race.hh"
#include "classInfo.hh"

//main method
int main() {
    //creates a pointer that "points" to the location of an object
    ifstream filePtr;
    
    // <Class> "instance of class";
    std::vector<Weapon> weapons;
    std::vector<Race> races;
    std::vector<ClassInfo> classinfos;
    std::vector<Condition> conditions;

    string name;
    string category;
    string dice;
    string type;

    //beginning of pointer for weaponsInfo
    filePtr.open("csvFiles/weaponsInfo.csv", ios::in);

    // checks that the return code is not -1 --> means error
    if (!filePtr) {
        return -1;
    }
    
    while (getline(filePtr, name, ',')) {
        getline(filePtr, category, ',') ;
        getline(filePtr, dice, ',') ;
        getline(filePtr, type);
        weapons.push_back(Weapon(name, category, dice, type));
    }

    filePtr.close();
    filePtr.open("csvFiles/classInfo.csv", ios::in);

    while (getline(filePtr, name, ',')) {
        getline(filePtr, dice);
        classinfos.push_back(ClassInfo(name, dice));
    }

    filePtr.close();
    filePtr.open("csvFiles/racesInfo.csv", ios::in);

    while (getline(filePtr, name)) {
        races.push_back(Race(name));
    }
    
    filePtr.close();
    filePtr.open("csvFiles/conditionsInfo.csv", ios::in);

    while (getline(filePtr, name)) {
        conditions.push_back(Condition(name));
    }

    filePtr.close();

    return 0;
}