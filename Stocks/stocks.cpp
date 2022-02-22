// Ranjana Rajagopalan
// 09/20/20
// This program will find total loss in money when buying and selling shares of stock.

#include <iostream>
using namespace std;

int main ()
{
    double total_paid;
    double total_sold;
    double loss;
    
    total_paid = 600*21.77;
    total_sold = 600*16.44;
    loss = total_paid - total_sold;
    
    cout << "The total amount paid for the stock is $" << total_paid << endl;
    cout << "The total amount received from selling the stock is $" << total_sold << endl;
    cout << "The total amount of money lost is $" << loss << endl;
    return 0;
}
