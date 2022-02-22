// Ranjana Rajagopalan
// 10/11/20
// positive.cpp
// This program checks to see whether a number is positive or negative and finds the absolute value of the number.

#include <iostream>
using namespace std;

int main ()
{
    double number;
    cout << "Enter a number to see if it is positive or negative: ";
    cin >> number;
    
    // checking whether the number is positive and finding its absolute value
    if (number > 0) { //positive
        cout << "The number " << number << " is positive and its absolute value is " << number << endl;
    } else if (number == 0) { // neutral
        cout << "The number " << number << " is neither positive nor negative and its absolute value is " << number << endl;
    } else { // negative
        cout << "The number " << number << " is negative and its absolute value is " << (number*-1) << endl;
    }

    return 0;
}
