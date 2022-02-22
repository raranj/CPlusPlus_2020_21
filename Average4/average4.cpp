// Ranjana Rajagopalan
// 09/27/20
// average4.cpp
// This program calculates the average of four integers.

#include <iostream>
using namespace std;

int main ()
{
    int int1, int2, int3, int4;
    double ave;
    cout << "Enter four integers separated by a space: " << endl;
    cin >> int1 >> int2 >> int3 >> int4;
    ave = static_cast<double>(int1 + int2 + int3 + int4) / 4;
    cout << "Your grades were: " << int1 << " " << int2 << " " << int3 << " " << int4 << endl;
    cout << "Your average grade is " << ave << endl;
    return 0;
}
