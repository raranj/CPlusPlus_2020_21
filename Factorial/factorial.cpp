// Ranjana Rajagopalan
// 10/23/20
// factorial.cpp
// This program calculates the factorial of a number.

#include <iostream>
#include <iomanip> //necessary for setw() function
using namespace std;

int main ()
{
    int num, fact, i;
    
    // Table Header
    cout << "Number" << setw(15) << "Factorial\n";
    
    num = 1;
    //Calculating Factorial 10 Times
    while (num <= 10)
    {
        fact = 1;
        i = 1;
        // Calculating the Factorial of Each Individual Number
        while (i <= num)
        {
            fact *= i;
            i++;
        }
        // Outputting Each Row of the Table
        cout << right << setw(6) << num << right << setw(14) << fact << endl;
        num++;
    }
        
    return 0;
}
