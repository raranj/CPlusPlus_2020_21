// Ranjana Rajagopalan
// 03/09/21
// revInt.cpp
// This program uses a recursive function to reverse an integer.

#include <iostream>
using namespace std;

void rev(int n);

int main ()
{
    int n;
    do
    {
        cout << "Enter a positive number you would like to reverse: ";
        cin >> n;
    } while (n < 0);// must be a positive number
    
    cout << "The reverse of " << n << " is ";
    rev(n);
    
    cout << endl;
    return 0;
}

void rev(int n)
{
    if (n < 10)
    {
        cout << n << endl;
    }
    else // two or more digits
    {
        cout << (n % 10);
        rev(n/10);
    }
}

