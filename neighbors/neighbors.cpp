// Ranjana Rajagopalan
// 01/28/21
// neighbors.cpp
// This program compares a value in a 2D array to its neighboring values.

#include <iostream>
using namespace std;

const int SIZE = 3;

int getInput(int ne[SIZE + 2][SIZE + 2]);
void setOuterPositions(int smallest, int ne[SIZE + 2][SIZE + 2]);

int main()
{
    int ne[SIZE + 2][SIZE + 2];
    int row, col, i, j, smallest;
    bool flag;
    
    smallest = getInput(ne);
    
    setOuterPositions(smallest, ne);
    
    // go through every element and check its neighbors
    for (row = 1; row < SIZE + 1; row++)
    {
        for (col = 1; col < SIZE + 1; col++)
        {
            flag = true; // true if ne[row][col] is bigger than all its neighbors
            
            for (i = -1; i <= 1; i++)
            {
                for (j = -1; j <= 1; j++)
                {
                    if ((i == 0) and (j == 0)) // don't want to compare element to itself
                        continue;
                    
                    if (ne[row][col] <= ne[row + i][col + j])
                    {
                        flag = false; // false when ne[row][col] is smaller or equal to one of its neighbors
                        break;
                    }
                }
                
                if (flag == false)
                    break; // no need to keep checking
            }
            
            if (flag == true)
            {
                cout << endl;
                cout << ne[row][col] << " in location (" << (row - 1) << ", " << (col - 1) << "). \n";
            }
        }
    }
    
    cout << endl;
    
    return 0;
}

/* This function takes the 2D array as an argument, and gets the user input for each position
 * of the array excluding the outermost positions. It returns the smallest value
 * inputted into the array.
 */
int getInput(int ne[SIZE + 2][SIZE + 2])
{
    int rowInput, colInput, smallest = 0;
    
    for (rowInput = 1; rowInput <= SIZE; rowInput++)
    {
        for (colInput = 1; colInput <= SIZE; colInput++)
        {
            cout << "row " << (rowInput) << ", column " << (colInput) << ": \n";
            cin >> ne[rowInput][colInput]; // get user input
            if ((rowInput == 1) and (colInput == 1))
            {
                smallest = ne[rowInput][colInput]; //initializing smallest
            }
            else
            {
                if (ne[rowInput][colInput] < smallest)
                {
                    smallest = ne[rowInput][colInput];
                }
            }
        }
    }
    
    return smallest;
}

/* This function sets the outermost positions of the 2D array to
 * the (smallest value of array - 1) to make it easier to compare with its neighbors.
 */
void setOuterPositions(int smallest, int ne[SIZE + 2][SIZE + 2])
{
    int row, col;
    
    for (row = 0; row < SIZE + 2; row++)
    {
        for (col = 0; col < SIZE + 2; col++)
        {
            if ((row == 0) or (row == 4) or (col == 0) or (col == 4))
                ne[row][col] = smallest - 1;
        }
    }
}
