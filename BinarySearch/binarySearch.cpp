// Ranjana Rajagopalan
// 02/06/21
// BinaryStringSearch.cpp
// This program searches an array of strings for the word selected by the user.

#include <iostream>
using namespace std;

void getUserInput(string array[]);
void BubbleSort(string array[]);
int BinarySearch(string array[]);
void outputWord(int position, string array[]);

const int n = 10;

int main()
{
    string array[n];
    int position;
    
    getUserInput(array);
    BubbleSort(array);
    position = BinarySearch(array);
    outputWord(position, array);
    
    return 0;
}

// This function inputs the elements of the array of strings from the user.
void getUserInput(string array[])
{
    int i;
    
    cout << "Enter " << n << " words.\n";
    
    for (i = 0; i < n; i++)
    {
        cout << "Word " << (i + 1) << ": ";
        cin >> array[i];
    }
}

// This function sorts the array in increasing order.
void BubbleSort(string array[])
{
    string temp;
    bool madeAswap;
    
    do
    {
        madeAswap = false;
        for (int count = 0; count < (n - 1); count++)
        {
            if(array[count] > array[count + 1])
            {
                temp = array[count];
                array[count]  = array[count + 1];
                array[count + 1] = temp;
                madeAswap = true;
            }
        }
    
    } while(madeAswap);
}

int BinarySearch(string array[])
{
    int low, high, mid;
    string word;
    bool done = false;
    
    cout << "What word would you like to search for? ";
    cin >> word;
    
    low = 0;
    high = n - 1;
    mid = 0;
    
    while ((low <= high) and (done == false))
    {
        mid = (low + high) / 2;
        
        if(array[mid] == word)
            done = true;
        else if (array[mid] > word)
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    if (done == false)
    {
        cout << "\nThe word you are searching for is not in the list.\n";
        exit(0);
    }
    
    return mid;
}

void outputWord(int position, string array[])
{
    int i;
    
    cout << "Here are the words after being sorted in ascending order: \n";
    
    for (i = 0; i < n; i++)
    {
        cout << "Word " << (i + 1) << ": " << array[i] << endl;
    }
    cout << "\nYour word was found in word " << (position + 1) << ".\n";
}
