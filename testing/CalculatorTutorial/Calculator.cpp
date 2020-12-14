#include "Calculator.h"
//the Calculate function's info
double Calculator::Calculate(double x, char oper, double y)
{
    //calculate function's code
    switch (oper) 
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    default:
        return 0.0;
    }
}
