// Ranjana Rajagopalan
// 10/04/20
// currency.cpp
// This program converts US currency to currency from South Korea and China.

#include <iostream>
#include <iomanip> // needed for setprecision()
using namespace std;

int main ()
{
    double dollar, won, yuan;
    cout << "Enter the amount of money (in dollars) you want converted: " << endl;
    cin >> dollar; // inputting the amount of money
    
    //if the amount of money entered is negative, program stops
    if (dollar < 0)
    {
        cout << "You can't enter a negative amount of money." << endl;
        return 0;
    }
    
    won = dollar / 0.00093; //converting to won
    yuan = dollar / 0.16; //converting to yuan
    
    cout << showpoint << fixed << setprecision(2) <<
    "$" << dollar << " is " << won <<
    " South Korean Won, and " << yuan << " Chinese Yuan.\n"; //outputting values
    
    return 0;
}
