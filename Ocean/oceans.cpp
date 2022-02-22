// Ranjana Rajagopalan
// 09/20/20
// This program computes how much ocean levels rise in 20 years.

#include <iostream>
using namespace std;

int main()
{
    double rise_per_year = 3.1;
    double rise;
    
    rise = rise_per_year*20;
    
    cout << "The rise of the ocean in 20 years is " << rise/10 << " cm.\n";
    cout << "The rise of the ocean in 20 years is " << (rise/10)/2.54 << " in.\n";
    return 0;
}
