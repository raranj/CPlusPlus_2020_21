// Ranjana Rajagopalan
// 11/22/20
// pascal.cpp
// This program displays the first 7 rows of Pascal's triangle.

#include <iostream>
#include <iomanip> // used for setw() function
using namespace std;

// function prototypes
int comb(int n, int k);
int fact(int num); // calculates factorial of a number

int main ()
{
    int row, col, number, n = 8;
    for (row = 0; row <= 6; row++)
    {
        cout << setw(n); //setting the width for each row to print
        for (col = 0; col <= row; col++) // print all the columns for each row
        {
            number = comb(row, col);
            cout << number << " ";
        }
        
        cout << endl;
        n--; // decrementing the indent for the setw() function
    }
    cout << endl;
    
    return 0;
}

int comb(int n, int k) 
{
    int result;
    
    result = fact(n)/(fact(k)*fact(n-k));
    
    return result;
}

int fact(int num)
{
    int i, factorial;
    
    factorial = 1;
    for (i = 1; i <= num; i++)
    {
        factorial *= i;
    }
    
    return factorial;
}
