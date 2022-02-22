// Ranjana Rajagopalan
// 02/28/21
// movies.cpp
// This program finds the mean, median, and mode of a dataset.

#include <iostream>
#include <iomanip> // needed for setprecision() function
using namespace std;

void UserArrayInput(int *a, int size);
void findAverage(int *a, int size);
void SelectionSort(int *a, int size);
int FindMax(int *a,int start);
void Swap(int *a,int p1,int p2);
void FindMode(int *a, int size);
void FindMedian(int *a, int size);

int main ()
{
    int *a = nullptr;
    int size;
    
    do
    {
        cout << "How many students are being surveyed? ";
        cin >> size;
        
        if (size <= 0)
        {
            cout << "Enter a positive number of students.\n";
        }
    } while (size <= 0); // Should be a positive number of elements in the array.
    
    
    a = new int[size];
    
    UserArrayInput(a, size);
    
    SelectionSort(a, size);
    
    findAverage(a, size);
    FindMode(a, size);
    FindMedian(a, size);
    
    delete [] a; // prevent memory leak
    a = nullptr;
    
    return 0;
}

// This function inputs the array elements.
void UserArrayInput(int *a, int size)
{
    int i;
    
    cout << "Enter the number of movies you watched this month. \n";
    for (i = 0; i < size; i++)
    {
        cout << "Student " << (i + 1) << ": ";
        cin >> *(a + i);
    }
}

// This function finds and prints the mean of all elements in the array.
void findAverage(int *a, int size)
{
    double average;
    int i, sum;
    
    sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += *(a + i);
    }
    
    average = static_cast<double>(sum) / size; // prevents integer division
    
    cout << "The average number of movies watched per month is " << fixed << setprecision(2) << average << ".\n";
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

// This function finds and prints the mode of the array.
void FindMode(int *a, int size)
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
    
    cout << "The number of movies watched per month most frequently is " << mode << ".\n";
}

// This function finds and returns the median of the sorted array.
void FindMedian(int *a, int size)
{
    double midNum1, midNum2, mid;
    
    // If there are an even number of elements, average the two middle elements.
    if (size % 2 == 0)
    {
        midNum1 = *(a + ((size/2) - 1));
        midNum2 = *(a + (size/2));
        mid = (midNum1 + midNum2) / 2;
    }
    else // if there are an odd number of elements
    {
        mid = *(a + (size/2));
    }
    
    cout << "The median number of movies watched in a month by college students is " << fixed << setprecision(2) << mid << ".\n";
}
