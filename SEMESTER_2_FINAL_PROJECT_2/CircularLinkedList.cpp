// Ranjana Rajagopalan
// 05/17/21

#include <iostream>
using namespace std;

// The class SuitorNode contains a pointer that points
// to the next node in the list as well as an integer that
// holds the position of a suitor. It also contains functions
// that set a pointer to the next node in the list, return the
// position of the suitor, and return the pointer to the node.
class SuitorNode
{
private:
    class SuitorNode *next; // next node in linked list
    int num; // place in line
public:
    SuitorNode(int initialnum)
    {
        num = initialnum;
    }
    int getNum() const;
    class SuitorNode* getNext() const;
    void setNext(class SuitorNode *nextNode);
};

// This function returns the position of the suitor in line.
int SuitorNode::getNum() const
{
    return num;
}

// This function returns a pointer to the next node in the list.
class SuitorNode* SuitorNode::getNext() const
{
    return next;
}

// This function sets the pointer to the next node in the list.
void SuitorNode::setNext(class SuitorNode *nextNode)
{
    next = nextNode;
}

// function prototypes
class SuitorNode* getSuitors();
void findLastSuitor(class SuitorNode*);

// eliminate after every two nodes
const int ELIMINATE = 2;

int main()
{
    class SuitorNode *head;
   
    head = getSuitors();
    findLastSuitor(head);
    
    // head can not be used because it might have been deleted
    
    return 0;
}

// This function inputs the number of suitors and creates
// a linked list of suitors. The function returns
// the a pointer to the head of the list.
class SuitorNode* getSuitors()
{
    int numSuitors;
    class SuitorNode *suitor, *head, *last = nullptr;
    
    head = NULL;
    
    do
    {
        cout << "Enter the number of suitors: ";
        cin >> numSuitors;
    } while (numSuitors <= 0);
    
    for (int i = 0; i < numSuitors; i++)
    {
        suitor = new class SuitorNode(i+1); // create a new node for each suitor
        
        if (i == 0)
        {
            head = suitor;
        }
        else
        {
            last->setNext(suitor);
        }
        
        suitor->setNext(head);
        last = suitor;
    }
    
    return head;
}

// This function deletes every third node
// until there is one node left. The function prints
// the number in the final node.
void findLastSuitor(class SuitorNode* head)
{
    SuitorNode *ptr, *last;
    int i = 0;
    
    ptr = head; // pointer that moves down the list
    last = head; // keeps track of the node before ptr
    
    while (ptr != ptr->getNext()) // while there is more than one node remaining
    {
        // until you reach the third node
        for (i = 0; i < ELIMINATE; i++)
        {
            // increment the pointers
            last = ptr;
            ptr = ptr->getNext();
        }
        
        last->setNext(ptr->getNext()); //point the last node to one node past the deleted
        
        cout << "Eliminating Suitor #" << ptr->getNum() << ".\n";
        delete ptr; // delete the pointer to the node
        ptr = last->getNext(); // set the pointer to the next node
    }
    
    cout << "\nYou should be at position #" << ptr->getNum() << " to win.\n\n";
}
