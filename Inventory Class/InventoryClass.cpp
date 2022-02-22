// Ranjana Rajagopalan
// 04/18/21
// InventoryClass.cpp

#include <iostream>
using namespace std;

class Inventory
{
private:
    int itemNumber;
    int quantity; // how many of the item there is
    double cost; // cost of individual item
public:
    Inventory()
    {
        itemNumber = 0;
        quantity = 0;
        cost = 0;
    }
    
    Inventory(int itemNumber, int quantity, double cost)
    {
        getItemNumber(itemNumber);
        getQuantity(quantity);
        getCost(cost);
    }
    
    void getItemNumber(int itemNum)
    {
        itemNumber = itemNum;
    }
    
    void getQuantity(int quan)
    {
        quantity = quan;
    }
    
    void getCost(double itemCost)
    {
        cost = itemCost;
    }
    
    double getTotalCost()
    {
        return (quantity * cost);
    }
    
    int ItemNumber()
    {
        return itemNumber;
    }
};

int main()
{
    Inventory item1(3000, 10, 1.50);
    Inventory item2(500, 100, 3.00);
    
    cout << "The item number of the first item is " << item1.ItemNumber() << endl;
    cout << "The total cost for the first item is $" << item1.getTotalCost() << endl;
    
    cout << "The item number of the second item is " << item2.ItemNumber() << endl;
    cout << "The total cost for the second item is $" << item2.getTotalCost() << endl;
  
    return 0;
}
