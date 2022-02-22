// Ranjana Rajagopalan
// 02/14/21
// SearchBenchmarks.cpp
// This program tracks the number of comparisons
// made for the linear and binary search algorithms.

#include <iostream>
using namespace std;

const int n = 20;

void UserArrayInput(int a[]);
int PickNumber(int a[]);
int LinearSearch(int a[], int num);
int BinarySearch(int a[], int num);
void SelectionSort(int a[]);
int FindMax(int a[],int start);
void Swap(int a[],int p1,int p2);

int main()
{
    int a[n];
    int num, LinearCount, BinaryCount;
    
    UserArrayInput(a);
    num = PickNumber(a);
    LinearCount = LinearSearch(a, num);
    BinaryCount = BinarySearch(a, num);
    
    cout << "It took " << LinearCount << " comparison(s) for the linear search algorithm to find the value " << num << ".\n";
    
    cout << "It took " << BinaryCount << " comparison(s) for the binary search algorithm to find the value " << num << ".\n";
    
    return 0;
}

// This function inputs the array elements from the user.
void UserArrayInput(int a[])
{
    int i;
    
    cout<< "Enter " << n << " integers.\n";
    
    for (i = 0; i < n; i++)
    {
        cout << "Element " << (i + 1) << ": ";
        cin >> a[i];
    }
}

// This function returns the number the user wants to search for.
int PickNumber(int a[])
{
    int num;
    
    cout << "Which number would you like to search for?\n";
    cin >> num;
    
    return num;
}

// This function implements the linear search algorithm and
// tracks how many comparisons it takes to find the right value.
int LinearSearch(int a[], int num)
{
    int index = 0;
    bool found = false;
    
    while ((index < n) and (found == false))
    {
        if (a[index] == num)
        {
            found = true;
        }
        
        index++;
    }
    
    if (found == false)
    {
        cout << "The value you were searching for was not located.\n";
        exit(0);
    }
    
    return index;
}

// This function implements the binary search algorithm and
// tracks how many comparisons it takes to find the right value.
int BinarySearch(int a[], int num)
{
    SelectionSort(a); // array must be sorted before performing binary search
    
    int first = 0;
    int last = n - 1;
    int count = 0;
    int mid;
    bool found = false;
    
    while ((first <= last) and (found == false))
    {
        mid = (first + last) / 2;
        
        if (a[mid] == num)
        {
            found = true;
        }
        else if (a[mid] > num)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
        
        count++;
    }
    
    if (found == false)
    {
        cout << "The value you were searching for was not located.\n";
        exit(0);
    }
    
    return count;
}

// This function sorts the array in ascending order
// so the binary search algorithm can be implemented.
void SelectionSort(int a[])
{
    int i, index;
    
    for(i = n-1; i > 0; i--)
    {
        index = FindMax(a,i);
        Swap(a,i,index);
    }
}

// This function finds the maximum value in the
// array and returns the index of that value.
int FindMax(int a[],int start)
{
    int i, max, maxIndex;
    
    max = a[start];
    maxIndex = start;
    
    for(i = start - 1; i >= 0; i--)
    {
        // change max and maxIndex if a larger value is found
        if (a[i] > max)
        {
            max = a[i];
            maxIndex = i;
        }
    }
    
    return maxIndex; // index of the maximum value in the array
}

// This function swaps the elements at indices p1 and p2.
void Swap(int a[],int p1,int p2)
{
    int temp = a[p1];
    a[p1] = a[p2];
    a[p2] = temp;
}
