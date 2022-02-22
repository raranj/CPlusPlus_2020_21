// Ranjana Rajagopalan
// 01/12/21
// power2.cpp
// This program prints the first six powers of 2 using an array.

#include <iostream>
#include <cmath> // used for power function
using namespace std;

int main ()
{
    // not initializing the array in the declaration
    int power2[6]; //array with 6 elements
    int i;
    
    // for each element (0 - 5) in the array
    for (i = 0; i < 6; i++)
    {
        // array element = 2^subscript
        power2[i] = pow(2, i);
        
        //display each element in the array
        cout << power2[i] << " ";
    }
    cout << endl;
    
    return 0;
}


