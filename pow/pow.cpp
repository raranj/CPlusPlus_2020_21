// Ranjana Rajagopalan
// 03/13/21
// pow.cpp
// This program uses a recursive function to find the power of a number.

#include <iostream>
#include <iomanip> // needed for setprecision() function
using namespace std;

float power(float base, int power);

int main ()
{
    float b;
    int p;
    
    cout << "Enter the base: ";
    cin >> b;
    
    do
    {
        cout << "Enter the exponent: ";
        cin >> p;
    } while (p < 0); // p must be nonnegative
    
    cout << "The result is " << fixed << setprecision(2) << power(b, p) << ".\n";
    
    return 0;
}

float power(float base, int p)
{
    if (p == 0) // base case
        return 1;
    else
        return base * power(base, p - 1);
}
