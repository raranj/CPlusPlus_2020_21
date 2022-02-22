// Ranjana Rajagopalan
// 10/04/20
// interest.cpp
// This program calculates final balance given the interest rate, principal, and number of times the interest is compounded.

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
    double rate, principal, timeComp, amount;
    
    cout << "Enter the principal amount: ";
    cin >> principal;
    
    cout << "Enter the interest rate: ";
    cin >> rate;
    
    cout << "Enter the number of times compounded annually: ";
    cin >> timeComp;
    
    if (principal < 0)
    {
        cout << "This program does not accept negative inputs.\n";
        return 0;
    }
    
    if (rate < 0)
    {
        cout << "This program does not accept negative inputs.\n";
        return 0;
    }
    
    if (timeComp < 0)
    {
        cout << "This program does not accept negative inputs.\n";
        return 0;
    }
    // breaking the calculation into smaller steps
    rate /= 100;
    amount = 1 + (rate / timeComp);
    amount = pow(amount, timeComp);
    amount *= principal;
    
    cout << showpoint << fixed << setprecision(2) <<
    "Interest rate: " << rate*100 << "\n" <<
    "Times Compounded: " << timeComp << "\n" <<
    "Final balance: $" << amount << endl;
    
    return 0;
    
    
}
