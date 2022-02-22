// Ranjana Rajagopalan
// 10/18/20
// summer.cpp
// This program prints the months during the summer using a switch statement.

#include <iostream>
using namespace std;

int main ()
{
    int month;
    cout << "Enter a number corresponding to a number in the summer (i.e. June = 6): " << endl;
    cin >> month;
    
    // Checking to see whether the input is within range
    if ((month < 1) || (month > 12))
    {
        cout << "Your input number is out of range\n";
        return 0;
    }
    
    switch (month)
    {
        case 6: cout << "June\n";
              break;
        case 7: cout << "July\n";
              break;
        case 8: cout << "August\n";
              break;
        default: cout << "The month is not in the summer.\n";
              break;
    }

    return 0;
}
