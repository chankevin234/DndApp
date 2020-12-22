//main method
// #include adds the libraries or calls the header files
#include <iostream>
#include <fstream>
#include <vector>
#include "dndBackend.hpp"

//main method
DndBackend::DndBackend() {
    //creates a pointer that "points" to the location of an object
    ifstream filePtr;
    
    //local vars
    string name;
    string category;
    string dice;
    string type;

    //beginning of pointer for weaponsInfo
    filePtr.open("csvFiles/weaponsInfo.csv", ios::in);
    
    //WHILE getting info from each line og the csv file...
    //get lines of info and put into the local vars (ex. name)
    while (getline(filePtr, name, ',')) {
        getline(filePtr, category, ',') ;
        getline(filePtr, dice, ',') ;
        getline(filePtr, type);
        //creates a new object "Weapon" with the values of the local vars
        weapons.push_back(new Weapon(name, category, dice, type));
    }

    filePtr.close();

    //beginning of pointer for classInfo
    filePtr.open("csvFiles/classInfo.csv", ios::in);

    while (getline(filePtr, name, ',')) {
        getline(filePtr, dice);
        //create a new object ClassInfo 
        classinfos.push_back(new ClassInfo(name, dice));
    }

    filePtr.close();

    //beginning of racesInfo
    filePtr.open("csvFiles/racesInfo.csv", ios::in);

    while (getline(filePtr, name)) {
        races.push_back(new Race(name));
    }
    filePtr.close();
    
    //beginning of conditionsInfo
    filePtr.open("csvFiles/conditionsInfo.csv", ios::in);

    while (getline(filePtr, name)) {
        conditions.push_back(new Condition(name));
    }

    filePtr.close();
}

//these contain the logic of the functions called in the extend within dndBackend.hh
//"string" indicates that it will return a string
// :: indicates that the class is DndBackend while the function is getRaceAtIndex
string DndBackend::getRaceAtIndex(int i) {
    //returns a string value into the "races" array. 
    // "->" means that it is pointing to the value at the location of the name object  
    return races[i]->name;
}

string DndBackend::getConditionAtIndex(int i) {
    //returns the conditions array
    return conditions[i]->name;
}

string DndBackend::getClassesAtIndex(int i) {
    return classinfos[i]->name + "," + classinfos[i]->hit_dice;
}

string DndBackend::getWeaponAtIndex(int i) {
    return weapons[i]->name + "," + weapons[i]->category + "," + weapons[i]->damage_dice + "," + weapons[i]->damage_type  + ",";
}
