// Ranjana Rajagopalan
// 11/08/20
// mathTutor.cpp
// This program allows you to pick a math problem to solve.

#include <iostream>
using namespace std;

int main ()
{
    char choice;
    double num1, num2, result;
    
    do
    {
        do // displaying the menu
        {
            cout << "\nTutoring Menu: \n";
            cout << "Enter '+' for an addition problem.\n";
            cout << "Enter '-' for a subraction problem.\n";
            cout << "Enter '*' for a multiplication problem.\n";
            cout << "Enter '#' to quit the program.\n";
            cin >> choice;
            
            if ((choice != '+') && (choice != '-') && (choice != '*') && (choice != '#'))
            {
                cout << "You have not entered a valid character.\n"; //validating input
            }
            else
            {
                break;
            }
        } while (true);

        if (choice == '#') // do not proceed if '#' has been entered
        {
            cout << "The program has been quit.\n";
            return 0;
        }

        cout << "Enter two numbers separated by a space: \n";
        cin >> num1 >> num2;
        
        switch (choice) //carrying out the operations
        {
            case '+': result = num1 + num2;
                    cout << "The sum of " << num1 << " and " << num2 << " is " << result << endl;
                    break;
            case '-': result = num1 - num2;
                    cout << "The difference of " << num1 << " and " << num2 << " is " << result << endl;
                    break;
            case '*': result = num1*num2;
                    cout << "The product of " << num1 << " and " << num2 << " is " << result << endl;
                    break;
            default:  // should never be executed because choice is validated above
                    break;
        }
        cout << endl;
    } while (true); 
    
    return 0;
}
