// Ranjana Rajagopalan
// 01/24/21
// Eratosthenes.cpp
// This program finds a set of prime numbers from 2 - 100.

#include <iostream>
using namespace std;

int main ()
{
    const int MIN_NUM = 2; // have to start from two to eliminate all composite numbers
    const int MAX_NUM = 100;
    
    int prime[MAX_NUM - MIN_NUM + 1];
    
    // MAX_NUM can not be less than MIN_NUM
    if (MAX_NUM < MIN_NUM)
    {
        cout << "Error: maximum can not be less than minimum.\n";
        return -1;
    }
    
    // initialize every element to 1
    for (int i = 0; i < MAX_NUM - MIN_NUM + 1; i++)
    {
        // prime[i] == 1 indicates (i + MIN_NUM) is prime
        prime[i] = 1;
    }
    
    // check for composite numbers
    for (int count = MIN_NUM; count <= MAX_NUM; count++)
    {
        if (prime[count - MIN_NUM] != 0) // check if number has already been crossed out
        {
            for (int i = MIN_NUM; i*count <= MAX_NUM; i++)
                prime[(count * i) - MIN_NUM] = 0; // composite numbers get converted to 0
        }
    }
    
    for (int i = 0; i <= MAX_NUM - MIN_NUM; i++)
    {
        if (prime[i] != 0)
            cout << i + MIN_NUM << " "; // print prime numbers
    }
    
    cout << endl;
    return 0;
}
