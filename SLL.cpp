#include "SLL.h"
#include <iostream>

using namespace std;

template <class Node>

SLL<Node>::SLL()
{
    start=NULL;
    last=NULL;
    ploc=NULL;
    loc=NULL;
}

template <class Node>

bool SLL<Node>::isEmpty()
//Checks if the list is empty or not.
{
    return start == NULL;
}

template <class Node>

void SLL<Node>::InsertAtFront(int value)
//Inserts a specified value at the start of the list.
{
    Node *newNode = new Node();
    newNode->data = value;

    if (!isEmpty())
    {

        newNode->next = start;
        start = newNode;
    }
    else
    {

        newNode->next = NULL;
        start = last = newNode;
    }
}

template <class Node>

void SLL<Node>::InsertAtEnd(int value)
//Inserts a specified value at the end of the list.
{
    Search(value);
    Node *newNode = new Node();
    newNode->data = value, newNode->next = NULL;
    if (!isEmpty())
    {

        last->next = newNode;
        last = newNode;
    }
    else
    {

        start = last = newNode;
    }
}

template <class Node>

void SLL<Node>::PrintList()
//Prints the entire list.
{
    if (!isEmpty())
    {
        Node *temp;
        temp = start;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl
             << endl;
    }
    else
        cout << "List is empty. Nothing to print." << endl
             << endl;
}

template <class Node>

void SLL<Node>::Search(int value)
//Searches a value and stores its next in loc.
{
    loc = start, ploc = NULL;
    while (loc != NULL && loc->data < value)
    {
        ploc = loc;
        loc = loc->next;
    }
    if (loc != NULL && loc->data != value)
        loc = NULL;
}

template <class Node>

void SLL<Node>::InsertSorted(int value)
//Inserts a specified value in ascending order.
{
    if (!isEmpty())
    {
        Search(value);
        if (loc == NULL)
        {
            if (ploc == NULL)
                InsertAtFront(value);
            else
            {
                Node *newNode = new Node();
                newNode->data = value;
                newNode->next = ploc->next;
                ploc->next = newNode;
                if (ploc == last)
                {
                    last == newNode;
                }
            }
        }
        else
            cout << "Value already exists." << endl
                 << endl;
    }
    else
        InsertAtFront(value);
}

template <class Node>

void SLL<Node>::DeleteValue(int value)
//Deletes a specified value from the list.
{
    if (!isEmpty())
    {
        Search(value);
        {
            if (loc != NULL)
            {
                if (loc == start)
                {
                    start = loc->next;
                    delete loc;
                }
                else if (loc == last)
                {
                    last = ploc;
                    delete loc;
                    ploc->next = NULL;
                }
                else
                {
                    ploc->next = loc->next;
                    delete loc;
                }
            }
        }
    }
    else
        cout << "List is empty." << endl
             << endl;
}

template <class Node>

void SLL<Node>::DeleteList()
//Deletes the entire list
{
    Node *temp;
    while (start != NULL)
    {
        temp = start;
        start = start->next;
        delete temp;
    }
    last = NULL;
    cout << "Deleting the list..." << endl
         << "List deleted successfully!" << endl
         << endl;
}
