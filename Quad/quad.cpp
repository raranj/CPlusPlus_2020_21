// Ranjana Rajagopalan
// 10/15/20
// quad.cpp
// This program uses the quadratic formula to solve a quadratic equation.

#include <iostream>
#include <cmath> // needed for sqrt() function
using namespace std;

int main ()
{
    double a, b, c, x, sqrtx, root1, root2;
    cout << "Enter values for a, b, and c separated by a space: " << endl;
    cin >> a >> b >> c;
    
    // if a == 0, then don't continue
    if (a == 0)
    {
        cout << "This is not a quadratic equation since a is 0.\n";
        return 0;
    }
    
    // checking what is inside the square root (negative or positive)
    x = (pow(b, 2) - 4*a*c);
    
    // if the discriminant is negative, display that there are no real solutions
    if (x < 0)
    {
        cout << "The equation has no real solutions.\n";
        return 0;
    }
    
    // calculating using the quadratic formula
    sqrtx = sqrt(x);
    root1 = (-b + sqrtx)/(2*a);
    root2 = (-b - sqrtx)/(2*a);
    
    // displaying the number of solutions
    if (root1 == root2)
        cout << "The equation has one solution, " << root1 << "." << endl;
    else
        cout << "The equation has two solutions, " << root1 << " and " << root2 << ".\n";
    
    return 0;
}
