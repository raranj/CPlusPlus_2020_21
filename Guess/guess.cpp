// Ranjana Rajagopalan
// 02/05/21
// guess.cpp
// This program inputs a number from the user and guesses the number with as less tries as possible.

#include <iostream>
#include <cctype> // for toupper() function
using namespace std;

void initialize();
int guessNumber();
void outputNumber(int mid);

const int MAX = 50;
const int MIN = 1;

int main()
{
    int num;
    
    initialize();
    num = guessNumber();
    outputNumber(num);
}

// This function explains what to do to the user.
void initialize()
{
    cout << "Think of a number between " << MIN << " and " << MAX << " and I will guess it.\n";
    cout << "Answer Y/y or N/n to my questions.\n";
}

// This function guesses the number by asking the least possible number of questions.
int guessNumber()
{
    int first = MIN; // first number in the range
    int last = MAX; // last number in the range
    int mid; // midpoint every time the range decreases by half
    bool done = false; // flag checks when the number has been guessed
    char ans; // inputs the user's answers
    
    do
    {
        mid = (first + last) / 2;
        cout << "Is your number " << mid << "?\n";
        cin >> ans;
        ans = toupper(ans);
        
        if (ans == 'Y')
        {
            done = true; // exit the loop, number has been found
        }
        else
        {
            cout << "Is your number less than " << mid << "?\n";
            cin >> ans;
            ans = toupper(ans);
            
            if (ans == 'Y')
                last = mid - 1; // decrease the range by making last the smallest possible value
            else
                first = mid + 1; // decrease range by making first the largest possible value
        }
    } while((first <= last) and (done == false));
      
    if (done == false)
    {
        cout << "You answered a question incorrectly or your number was not in the range " << MIN << " - " << MAX << ".\n";
        exit(0);
    }
    
    return mid;
}

// This function displays the number that was guessed to the user.
void outputNumber(int mid)
{
    cout << "Your number is " << mid << ".\n";
    cout << "I have succeeded in guessing your number!\n";
}
