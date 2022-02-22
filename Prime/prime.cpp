// Ranjana Rajagopalan
// 11/01/20
// prime.cpp
// This program lists all the prime numbers from 50 - 100.

#include <iostream>
#include <cmath> // needed for sqrt() function
using namespace std;

int main ()
{
    int num, count;
    
    num = 50;
    // num goes from 50 to 100
    while (num <= 100)
    {
        // initializing count to 2 for every num
        count = 2;
        while (count <= sqrt(num))
        {
            // if it is not prime, then break
            if ((num % count) == 0)
                break;
            count++;
        }
        // if all values of count have been tested, num must be prime
        if (count > sqrt(num))
            cout << num << endl;
        num++;
    }
    
    return 0;
}
