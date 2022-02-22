// Ranjana Rajagopalan
// 02/14/21
// median.cpp
// This program determines the median of a given array.

#include <iostream>
using namespace std;

const int n = 10; // changeable by user

void UserArrayInput(int *a);
void SortArray(int *a);
int FindMax(int *a,int start);
void Swap(int *a,int p1,int p2);
void FindMedian(int *a);

int main ()
{
    int a[n];
    
    UserArrayInput(a);
    SortArray(a);
    FindMedian(a);
    
    return 0;
}

// This function inputs the elements of the array from the user.
void UserArrayInput(int *a)
{
    int i;
    
    cout << "Enter the " << n << " elements.\n";
    
    for(i = 0; i < n; i++)
    {
        cout << "Element " << (i + 1) << ": ";
        cin >> *(a + i); // inputting array elements using a pointer
    }
}

// sorting the elements in ascending order
void SortArray(int *a)
{
    int i, index;
    
    for(i = n-1; i > 0; i--)
    {
        index = FindMax(a,i);
        Swap(a,i,index);
    }
}

/* This function finds the maximum value in the
* array from (0 - (start - 1)) and returns its index.
*/
int FindMax(int *a, int start)
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
    int temp = *(a  +p1);
    *(a + p1) = *(a + p2);
    *(a + p2) = temp;
}

// This function finds and prints the median of the sorted array.
void FindMedian(int *a)
{
    double midNum1, midNum2, mid;
    
    if (n % 2 == 0)
    {
        midNum1 = *(a + ((n/2) - 1));
        midNum2 = *(a + (n/2));
        mid = (midNum1 + midNum2) / 2;
    }
    else
    {
        mid = *(a + (n/2));
    }
    
    cout << "The median of the array is " << mid << ".\n";
}
