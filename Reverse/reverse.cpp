// Ranjana Rajagopalan
// 11/01/20
// reverse.cpp
// This program reverses the digits of a given number.

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    int num, rem, quotient;
    cout << "Enter a number: " << endl;
    cin >> num;
    
    // check for negative number
    if (num < 0)
        cout << "-";
    
    num = abs(num);
    // keep track of running quotient and remainder
    do
    {
        quotient = num / 10;
        rem = num % 10;
        cout << rem;
        num = quotient;
    } while (quotient != 0);
    
    cout << endl;
    return 0;
}
