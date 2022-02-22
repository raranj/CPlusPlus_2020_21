// Ranjana Rajagopalan
// 11/08/20
// population.cpp
// This program predicts the size of a population of organisms.

#include <iostream>
using namespace std;

int main ()
{
    int current, day, numDays;
    double perIncrease;
    cout << "Enter the starting number of organisms: \n";
    cin >> current;
    
    while (current <= 0) //input validation
    {
        cout << "Enter a positive value: \n";
        cin >> current;
    }
    
    cout << "Enter the average daily population increase as a percent from 0 - 100: \n";
    cin >> perIncrease;
    
    while ((perIncrease < 0) || (perIncrease > 100)) //input validation
    {
        cout << "Enter a percent increase value from 0 - 100: \n";
        cin >> perIncrease;
    }
    
    cout << "Enter the number of days they will multiply: \n";
    cin >> numDays;
    
    while (numDays <= 0) //input validation
    {
        cout << "Enter a positive number of days the population multiplies: \n";
        cin >> numDays;
    }
    
    perIncrease /= 100; // converting percent to decimal
    
    // looping through every day and outputting population
    for (day = 1; day <= numDays; day++)
    {
        cout << "Day " << day << endl;
        // Value of population is truncated because of integer values
        current = current + (perIncrease * current);
        cout << "The population is " << current << endl;
        cout << endl;
    }
    return 0;
}
