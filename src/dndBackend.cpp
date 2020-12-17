//main method
// #include adds the libraries or calls the header files
#include <iostream>
#include <fstream>
#include <vector>
#include "dndBackend.hh"

//main method
DndBackend::DndBackend() {
    //creates a pointer that "points" to the location of an object
    ifstream filePtr;

    string name;
    string category;
    string dice;
    string type;

    //beginning of pointer for weaponsInfo
    filePtr.open("csvFiles/weaponsInfo.csv", ios::in);
    
    while (getline(filePtr, name, ',')) {
        getline(filePtr, category, ',') ;
        getline(filePtr, dice, ',') ;
        getline(filePtr, type);
        weapons.push_back(new Weapon(name, category, dice, type));
    }

    filePtr.close();
    filePtr.open("csvFiles/classInfo.csv", ios::in);

    while (getline(filePtr, name, ',')) {
        getline(filePtr, dice);
        classinfos.push_back(new ClassInfo(name, dice));
    }

    filePtr.close();
    filePtr.open("csvFiles/racesInfo.csv", ios::in);

    while (getline(filePtr, name)) {
        races.push_back(new Race(name));
    }
    
    filePtr.close();
    filePtr.open("csvFiles/conditionsInfo.csv", ios::in);

    while (getline(filePtr, name)) {
        conditions.push_back(new Condition(name));
    }

    filePtr.close();
}