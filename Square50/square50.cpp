// Ranjana Rajagopalan
// 10/25/20
// square50.cpp
// This program lists a table of values for the squares of integers 1 - 50.

#include <iostream>
#include <iomanip> // needed for setw() function
using namespace std;

int main ()
{
    int i;
    
    // table header
    cout << "Number" << setw(10) << "Square\n";
    
    //printing out a value for the square every iteration
    for (i = 1; i <= 50; i++)
    {
        cout << setw(4) << i << setw(9) << (i * i) << endl;
    }
    
    return 0;
}
