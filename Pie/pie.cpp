// Ranjana Rajagopalan
// 02/21/21
// pie.cpp
// This program finds the mode of an array.

#include <iostream>
using namespace std;

void UserArrayInput(int *a, int size);
void SelectionSort(int *a, int size);
int FindMax(int *a,int start);
void Swap(int *a,int p1,int p2);
int FindMode(int *a, int size);

int main ()
{
    int size = 30;
    int mode;
    int a[size];
    
    UserArrayInput(a, size);
    SelectionSort(a, size);
    mode = FindMode(a, size);
    
    cout << "The number of pie slices eaten by the most people is "
    << mode << " slice(s).\n";
    
    return 0;
}

// This function inputs the array elements from the user.
void UserArrayInput(int *a, int size)
{
    int i;
    
    cout << "Enter the number of pie slices you ate in a year.\n";
    for (i = 0; i < size; i++)
    {
        cout << "Person " << (i + 1) << ": ";
        cin >> *(a + i);
    }
}

// This function sorts the array in ascending order.
void SelectionSort(int *a, int size)
{
    int i, index;
    
    for(i = (size - 1); i > 0; i--)
    {
        index = FindMax(a,i);
        Swap(a,i,index);
    }
}

// This function finds the maximum value in the
// array and returns the index of that value.
int FindMax(int *a,int start)
{
    int i, max, maxIndex;
    
    max = *(a + start);
    maxIndex = start;
    
    for(i = start - 1; i >= 0; i--)
    {
        // change max and maxIndex if a larger value is found
        if (*(a + i) > max)
        {
            max = *(a + i);
            maxIndex = i;
        }
    }
    
    return maxIndex; // index of the maximum value in the array
}

// This function swaps the elements at indices p1 and p2.
void Swap(int *a,int p1,int p2)
{
    int temp = *(a + p1);
    *(a + p1) = *(a + p2);
    *(a + p2) = temp;
}

int FindMode(int *a, int size)
{
    int i;
    int mode = *a;
    int value = *a;
    int count = 0;
    int modeCount = 0;
    
    for (i = 0; i < size; i++ )
    {
        if (*(a + i) == value)
        {
            count++;
        }
        else
        {
            if (count > modeCount)
            {
                mode = value;
                // if multiple values occur the same number of times
                // the smallest one will be outputted as the mode
                modeCount = count;
            }
            value = *(a + i);
            count = 1;
        }
    }
    
    return mode;
}
