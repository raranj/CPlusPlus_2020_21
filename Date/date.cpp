// Ranjana Rajagopalan
// 03/30/21
// date.cpp
// This program demonstrates the creation and usage of a class.

#include <iostream>
using namespace std;

// class declaration
class Date
{
private:
    int month;
    int date;
    int year;
    
    string convertMonth(int m) // converts numerical month to word
    {
        switch(m)
        {
            case 1: return "January";
            case 2: return "February";
            case 3: return "March";
            case 4: return "April";
            case 5: return "May";
            case 6: return "June";
            case 7: return "July";
            case 8: return "August";
            case 9: return "September";
            case 10: return "October";
            case 11: return "November";
            case 12: return "December";
            default: return nullptr; // should never be reached
        }
    }
public:
    void setMonth(int m)
    { month = m; }
    
    void setDate(int d)
    { date = d; }
    
    void setYear(int y)
    { year = y; }
    
    void numericalOutput(int month, int date, int year)
    {
        cout << month << "/" << date << "/" << year << endl;
    }
    
    void monthFirst(int month, int date, int year)
    {
        cout << convertMonth(month) << " " << date << ", "
        << year << endl;
    }
    
    void dateFirst(int date, int month, int year)
    {
        cout << date << " " << convertMonth(month)
        << " " << year << endl;
    }
};

int main ()
{
    int month, date, year;
    
    do
    {
        cout << "Enter the date: ";
        cin >> date;
    } while ((date < 1) || (date > 31)); // validates date
    
    do
    {
        cout << "Enter the month: ";
        cin >> month;
    } while ((month > 12) || (month < 1)); // month should be in between 1 & 12
   
    do
    {
        cout << "Enter the year: ";
        cin >> year;
    } while (year < 0);
        
    Date display; // declaring object
    
    display.setDate(date);
    display.setMonth(month);
    display.setYear(year);
    
    display.numericalOutput(month, date, year);
    display.monthFirst(month, date, year);
    display.dateFirst(date, month, year);
    
    return 0;
    
    
}

