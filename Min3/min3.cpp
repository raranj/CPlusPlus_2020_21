// Ranjana Rajagopalan
// 10/15/20
// min3.cpp
// This program calculates the minimum of three numbers.

#include <iostream>
using namespace std;

int main ()
{
    int num1, num2, num3;
    cout << "Enter three integers separated by a space to find which one is the smallest: ";
    cin >> num1 >> num2 >> num3;
    
    // Comparing the three numbers
    if (num1 >= num2)
    {
        if (num2 >= num3)
            cout << "The minimum number between " << num1 << ", " << num2 << " and " << num3 << " is " << num3 << endl;
        else
            cout << "The minimum number between " << num1 << ", " << num2 << " and " << num3 << " is " << num2 << endl;
    }
    else
    {
        if (num1 >= num3)
            cout << "The minimum number between " << num1 << ", " << num2 << " and " << num3 << " is " << num3 << endl;
        else
            cout << "The minimum number between " << num1 << ", " << num2 << " and " << num3 << " is " << num1 << endl;
    }

    return 0;
}
