// Ranjana Rajagopalan
// 11/15/20
// winningDivision.cpp
// This program determines which of a company's quarters has the best sales for a quarter.

#include <iostream>
#include <iomanip> //using the setprecision() function
using namespace std;

// function prototypes
double getSales(string division);
void findHighest(double sale1, double sale2, double sale3, double sale4);

int main()
{
    double NEsales, SEsales, NWsales, SWsales;
    
    // calling getSales() for each division
    NEsales = getSales("northeast");
    SEsales = getSales("southeast");
    NWsales = getSales("northwest");
    SWsales = getSales("southwest");
    
    // finding the division with the highest sales figure
    findHighest(NEsales, SEsales, NWsales, SWsales);
    return 0;
}

// this function inputs the sales value for each of the four divisions
double getSales(string division)
{
    double salesFigure;
    do //validating input
    {
        cout << "Enter a positive quarterly sales figure for the " << division << " division:\n";
        cin >> salesFigure;
    } while (salesFigure < 0);
    
    return salesFigure;
}

// this function finds the highest sales value and which division it belongs to
void findHighest(double NEsales, double SEsales, double NWsales, double SWsales)
{
    double greatest;
    string name;
    
    greatest = NEsales;
    name = "northeast";
    
    if (SEsales > greatest)
    {
        greatest = SEsales;
        name = "southeast";
    }
    if (NWsales > greatest)
    {
        greatest = NWsales;
        name = "northwest";
    }
    if (SWsales > greatest)
    {
        greatest = SWsales;
        name = "southwest";
    }
    cout << "The " << name << " division has the highest sales figure of " << fixed << setprecision(2) << "$" << greatest << ".\n";
}
