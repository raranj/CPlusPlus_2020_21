// Ranjana Rajagopalan
// 10/25/20
// mulByAdd.cpp
// This program multiplies two numbers using addition.

#include <iostream>
#include <cmath> // needed for abs() function
using namespace std;

int main ()
{
    int num1, num2, i, prod, smaller, bigger, abs1, abs2;
    cout << "Enter two numbers (separated by a space): " << endl;
    cin >> num1 >> num2;
    
    // changing the signs of num1 and num2 to positive
    abs1 = abs(num1);
    abs2 = abs(num2);
    
    // finding which integer is bigger and which one is smaller
    if (abs1 >= abs2)
    {
        bigger = abs1;
        smaller = abs2;
    }
    else
    {
        bigger = abs2;
        smaller = abs1;
    }

    // adding the number to itself as many times as necessary
    prod = 0;
    i = 1;
    while (i <= smaller)
    {
        prod += bigger;
        i++;
    }
    
    // changing the sign of the product back to its original sign
    if (((num1 <= 0) && (num2 <= 0)) ||
        ((num1 >= 0) && (num2 >= 0))) // sign is same for both numbers
    {
        cout << "The product of " << num1 << " and " << num2 << " is " << prod << endl;
    }
    else // sign of num1 is not same as sign of num2
    {
        cout << "The product of " << num1 << " and " << num2 << " is " << (prod*-1) << endl;
    }
    
    return 0;
    
}
