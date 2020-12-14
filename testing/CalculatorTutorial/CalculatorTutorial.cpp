// CalculatorTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.

//this calls the library
#include <iostream>
#include "Calculator.h"

using namespace std;

//main method/starting point at run-time
int main()
{
    //define default variables
    double x = 0;
    double y = 0;
    double result = 0;
    char oper = '+';

    cout << "Calculator Console Application \n\n";
    cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b \n";
    
    //create new object c from Class Calculator
    Calculator c;

    //keep looping if you have the condition x == 0; exit when x != 0
    while (x == 0) {
        cin >> x >> oper >> y;
        //c.Calculate calls the Calculate function 
        result = c.Calculate(x, oper, y);
        cout << "Result is " << result << endl;
    }
    
    return 0;
}

