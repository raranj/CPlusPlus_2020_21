// Ranjana Rajagopalan
// 02/02/21
// SelectionSort.cpp
// This program is a modified version of SelectionSort.cpp provided in class.

#include <iostream>
using namespace std;

const int n = 7; // array size

void Initialize(int a[]);
void SelectionSort(int a[]);
int FindMax(int a[],int start);
void Swap(int a[],int p1,int p2);
void Display(int a[]);

int main()
{
    int a[n];
    Initialize(a);
    SelectionSort(a);
    Display(a);
    return 0;
}

// inputting array elements from user
void Initialize(int a[])
{
    int i;
    
    cout<<"Enter the elements of the arrray."<<endl;
    cout<<"(The array has "<<n<<" elements)."<<endl;
    
    for(i=0;i<n;i++)
    {
        cout<<"a["<<i<<"] = ";
        cin>>a[i];
    }
}

// sorting the elements in ascending order
void SelectionSort(int a[])
{
    int i, index;
    
    for(i = n-1; i > 0; i--)
    {
        index = FindMax(a,i);
        Swap(a,i,index);
    }
}

// outputting the array after it has been sorted
void Display(int a[])
{
    int i;
    cout<<"\nThe sorted array: \n";
    
    for(i=0;i<n;i++)
       cout<<"a["<<i<<"]= "<<a[i]<<endl;
}

/* This function finds the maximum value in the
 * array from (0 - start - 1) and returns its index.
 */
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
