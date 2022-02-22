// Ranjana Rajagopalan
// RemoveD.cpp
// This program removes elements from an array that appear more than once.

#include <iostream>
using namespace std;

void UserArrayInput(int inparray[], int size);
void SelectionSort(int inparray[], int size);
int FindMax(int inparray[],int start);
void Swap(int inparray[],int p1,int p2);
int removedup(int inparray[], int size, int outarray[]);

const int SIZE = 10;

int main ()
{
    int inparray[SIZE];
    int outarray[SIZE];
    int newSize;
    
    UserArrayInput(inparray, SIZE);
    SelectionSort(inparray, SIZE);
    newSize = removedup(inparray, SIZE, outarray);
    
    cout << "Here is the array with potential duplicates: \n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << inparray[i] << " ";
    }
    
    cout << endl;
    
    cout << "The size of the new array is " << newSize << ".\n";
    
    cout << "Here is the new array without duplicates: \n";
    for (int i = 0; i < newSize; i++)
    {
        cout << outarray[i] << " ";
    }
    
    cout << endl;
    return 0;
}

// This function inputs the array elements from the user.
void UserArrayInput(int a[], int size)
{
    int i;
    
    cout << "Enter " << size << " integers.\n";
    
    for (i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": ";
        cin >> a[i];
    }
}

// This function returns the size of the new array without duplicates.
int removedup(int inparray[], int size, int outarray[])
{
    int i = 0, j;
    int tracker = 0; // keeps track of how many elements in new array
    while (i < size) // walking through the array
    {
        j = i + 1;
        
        while ((j < size) and (inparray[j] == inparray[i]))
            j++; // increment until new element is found
        
        outarray[tracker] = inparray[i];
        tracker++;
        i = j; // start over from element i in the array
    }
    return tracker;
}

// sorting the elements in ascending order
void SelectionSort(int inparray[], int size)
{
    int i, index;
    
    for(i = (size - 1); i > 0; i--)
    {
        index = FindMax(inparray,i);
        Swap(inparray,i,index);
    }
}

/* This function finds the maximum value in the
 * array from (0 - start - 1) and returns its index.
 */
int FindMax(int inparray[],int start)
{
    int i, max, maxIndex;
    
    max = inparray[start];
    maxIndex = start;
    
    for(i = start - 1; i >= 0; i--)
    {
        // change max and maxIndex if a larger value is found
        if (inparray[i] > max)
        {
            max = inparray[i];
            maxIndex = i;
        }
    }
    
    return maxIndex; // index of the maximum value in the array
}

// This function swaps the elements at indices p1 and p2.
void Swap(int inparray[],int p1,int p2)
{
    int temp = inparray[p1];
    inparray[p1] = inparray[p2];
    inparray[p2] = temp;
}

