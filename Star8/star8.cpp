// Ranjana Rajagopalan
// 11/01/20
// star8.cpp
// This program displays a square of 8 stars.

#include <iostream>
using namespace std;

int main ()
{
    int row, col;
    const int SIDE_LENGTH = 8;
    
    // SIDE_LENGTH rows of stars
    for (row = 0; row < SIDE_LENGTH; row++)
    {
        // SIDE_LENGTH columns for each row
        for (col = 0; col < SIDE_LENGTH; col++)
            cout << "*";
        cout << endl;
    }
    return 0;
}
