#include <iostream>
using namespace std;

class Races {                   //races Class
  public:                       //access specifier
    Races (string flagCalled) { //races Constructor --> flags call of class
      string flagCalled = "Races Class Called";         
      cout << flagCalled << "\n";
    }
  private:
    //private attribute
    string racesURL = "/races/";

  public:
    //setter
    void setRacesList(string races) {
      
    }
    //getter
    int getRacesList() {
      return racesList[];
    }
}


// main class
int main() {

  string name;
  
  cout << "Print your name \n";
  //input
  cin >> name;
  //output
  cout << "Hello, " << name << "\n";
  
  return 0;
}



