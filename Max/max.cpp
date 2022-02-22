// Ranjana Rajagopalan
// 10/11/20
// max.cpp
// This program finds the maximum of two integers.

#include <iostream>
using namespace std;

int main ()
{
    int int1, int2;
    cout << "Enter two integers separated by a space to find out which one is bigger: " << endl;
    cin >> int1 >> int2;

    //comparing to see which integer is bigger
    if (int1 > int2) {
        cout << "The maximum number between " << int1 << " and " << int2 << " is " << int1 << endl;
    } else if (int2 > int1) {
        cout << "The maximum number between " << int1 << " and " << int2 << " is " << int2 << endl;
    } else {
        cout << "The two numbers " << int1 << " and " << int2 << " are equal\n";
    }
    
    return 0;
}
