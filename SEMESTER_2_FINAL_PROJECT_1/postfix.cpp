// Ranjana Rajagopalan
// 05/13/21
// This program evaluates postfix expressions with stack frames.

#include <iostream>
#include <string> // needed for getline() function
using namespace std;

// The Stack class has a stack represented by an array
// that holds the integers entered by the user.
// It also has functions to push numbers into the stack,
// pop numbers out of the stack, and to check if the stack is empty.
class Stack
{
private:
    const static int MAX_STACK = 20; // number of possible integers in the stack
    int top; // index of top value in the stack
    int opndstk[MAX_STACK]; // array that represents the stack
public:
    Stack()
    {
        top = 0;
    }
    void push(int);
    int pop(int &);
    bool isEmpty();
};

// This function receives an integer as an argument
// and stores it at the top of the stack.
void Stack::push(int c)
{
    if (top == MAX_STACK) // number of operands can not exceed maximum number of indices
    {
        cout << "\nNumber of operands exceeds the maximum allowed.\n\n";
        exit(-1);
    }
    else
    {
        opndstk[top] = c;
        top++; // increment top once a value is assigned
    }
}

// This function pops out the top value in the stack and returns it by reference.
// Returns 0 on success and -1 on failure.
int Stack::pop(int &value)
{
    if (isEmpty() == true)
    {
        return -1;
    }
    else
    {
        top--; // decrement top when popped
        value = opndstk[top];
        return 0;
    }
}

// This function returns true when the stack is empty and false when it is not.
bool Stack::isEmpty()
{
    if (top == 0) // no elements
        return true;
    else
        return false;
}

string getInput();
int operations(char, int, int);
bool calculate(int &, string, size_t);
bool checkOperation(char);
    
int main()
{
    string exp;
    bool invalidExp;
    int result;
    size_t len;
    
    do
    {
        exp = getInput(); // expression inputted by user
        len = exp.length(); // length of expression
        
        if (len == 0) // if empty string entered, don't continue
        {
            cout << "The program has been quit.\n";
            return 0;
        }
        
        invalidExp = calculate(result, exp, len);
    
        if (invalidExp == true)
        {
            cout << "Invalid Expression.\n\n";
            continue;
        }
        
        cout << "\nThe value of your postfix expression is "
        << result << ".\n\n";
        
    } while (1);

    return 0;
}

// This function inputs and returns the postfix
// expression entered by the user.
string getInput()
{
    string expression;
    cout << "Enter a postfix expression to evaluate or Enter to quit. \n";
    cout << "Add a space after every integer.\n";
    cout << "Allowed operations are (+), (-), (*), integer division(/), and modulus(%).\n";
    getline(cin, expression); // getline() allows for spaces in between characters
    
    return expression;
}

// This function returns the value of the expression by reference.
// The function returns true if the expression entered is invalid,
// and false if the expression is valid and the value has been calculated.
bool calculate(int &result, string exp, size_t len)
{
    Stack s;
    bool invalidExp = false; // checks whether the expression is valid
    char c; // character that walks through the string inputted by user
    int num, num1, num2, i = 0;
    
    while (i < len) // while loop walks through the string
    {
        c = exp.at(i); // string.at() function walks through every character of the string
        
        if (isspace(c) == true) // return to the beginning of the loop if a space is entered
        {
            i++;
            continue;
        }
        
        if (isdigit(c) == true) // if the character is a digit
        {
            num = 0;
            do // if the operand inputted is more than single digit number
            {
                // c - '0' converts character to integer
                num = (num*10) + (c - '0');
                i++;
                // If the end of the string is reached, don't
                // continue because the expression is invalid.
                if (i == len)
                {
                    cout << "\nNot enough operations.\n";
                    return true;
                }
                
                c = exp.at(i);
            } while (isdigit(c) != false); // while the end of the number hasn't been reached
            
            s.push(num);
        }
        else // if character is an operation
        {
            if (checkOperation(c) == false)
                return true;
            
            if ((s.pop(num1)) == -1) // pop the first number from stack
            {
                cout << "\nNot enough operands for the " << c << " operation.\n";
                return true;
            }
            // if pop() returns -1 (happens when stack is empty)
            // the expression is invalid, and return true
            if ((s.pop(num2)) == -1) // pop second number from stack
            {
                cout << "\nNot enough operands for the " << c << " operation.\n";
                return true;
            }
            result = operations(c, num2, num1); // carry out the operation
            s.push(result); // push result back into stack
            
            i++; // move to the next character in the string
        }
        
    }
    
    if ((s.pop(result)) == -1) // should never happen
    {
        return true;
    }
    
    if (s.isEmpty() == false)
    {
        cout << "\nNot enough operations.\n";
        return true;
    }
        
    // shouldn't reach here if the expression inputted is invalid
    return invalidExp; // returns false
}

/* This function uses a switch statement to evaluate
 * the various operations entered by the user.
 * It receives the operation (+, -, *, /, or %) as well
 * as the two integers that were popped as arguments.
 */
int operations(char c, int x, int y)
{
    switch (c)
    {
        case '+': return (x + y);
                break;
        case '-': return (x - y);
                break;
        case '*': return (x * y);
                break;
        case '/': if (y == 0)
                {
                    cout << "\nCan't divide by 0.\n";
                    cout << "Invalid Operation.\n\n";
                    exit(-1);
                }
                return (x / y);
                break;
        case '%': if (y == 0)
                {
                    cout << "\nCan't mod by 0.\n";
                    cout << "Invalid Operation.\n\n";
                    exit(-1);
                }
                return (x % y);
                break;
        default: cout << c << "\n is an invalid input.\n\n"; // should never happen
               exit(-1);
    }
}

// This function returns true if the operation
// is valid, and false if it is invalid.
bool checkOperation(char c)
{
    switch (c)
    {
        case '+': return true;
        case '-': return true;
        case '*': return true;
        case '/': return true;
        case '%': return true;
        default: cout << endl << c << " is an invalid input.\n";
               return false;
    }
}
