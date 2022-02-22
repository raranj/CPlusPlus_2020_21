// Ranjana Rajagopalan
// 03/28/21
// quicksort.cpp
// This program implements the quicksort algorithm on a list of words.

#include <iostream>
#include <algorithm> // needed for swap() function
#include <cstdlib> // needed for rand() function
#include <ctime> // needed to generate random seed
using namespace std;

void quickSort(string *arr, int start, int end);
int partition(string *arr, int start, int end);
void Display(string *arr, int size);

int main()
{
    // dynamic memory allocation so user gets to decide how many words to sort
    string *arr = nullptr;
    int size;
    
    cout << "How many words would you like to sort? ";
    cin >> size;
    
    arr = new string[size];
    
    // inputting elements
    for (int i = 0; i < size; i++)
    {
        cout << "Word " << (i + 1) << ": ";
        cin >> arr[i];
    }
    
    cout << "Input Array: \n";
    Display(arr, size);
    
    quickSort(arr, 0, size-1);

    cout << "Sorted Array: \n";
    Display(arr, size);
    
    delete [] arr;
    arr = nullptr;
    
    return 0;
}

// This function sorts the array from arr[start] to arr[end]
void quickSort(string *arr, int start, int end)
{
    if (start < end)
    {
        // partition the array and get the pivot point
        int p = partition(arr, start, end);
        // sort the portion before the pivot
        quickSort(arr, start, p-1);
        // sort the portion after the pivot
        quickSort(arr, p+1, end);
    }
}

/* This function rearranges the elements of the array so that
 * elements less than the pivot are to the left and
 * elements greater than the pivot are to the right.
 */


int partition(string *arr, int start, int end)
{
    int seed = time(0);
    srand(seed); // set the seed before generating random number
    // random number between start and end
    int randomPivot = (rand() % (end - start + 1)) + start;
    
    // the pivot element is taken to be the element at the start of the subrange that needs to be partitioned
    string pivotValue = arr[randomPivot];
    int pivotPosition = randomPivot;
    
    // look right of the pivotPosition and move all smaller elements to its left
    for (int pos = pivotPosition + 1; pos <= end; pos++)
    {
        if (arr[pos] < pivotValue)
        {
            // swap the current item with the item to the right of the pivot
            swap(arr[pivotPosition + 1], arr[pos]);
             // swap the current item with the item to the right of the pivot element
            swap(arr[pivotPosition], arr[pivotPosition + 1]);
            
            pivotPosition++;
        }
    }
    
    // look left of the pivotPosition and move all larger elements to its right
    for (int pos = pivotPosition - 1; pos >= start; pos--)
    {
        if (arr[pos] > pivotValue)
        {
            // swap current element with element before pivot
            swap(arr[pos], arr[pivotPosition - 1]);
            // swap current element with the pivot
            swap(arr[pivotPosition], arr[pivotPosition - 1]);
            
            pivotPosition--;
        }
    }
    
    return pivotPosition;
}

// This function displays the elements of an array.
void Display(string *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}



