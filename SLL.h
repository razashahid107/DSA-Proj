#ifndef SLL_H
#define SLL_H

//template function
template <class Node>

class SLL
//Singly linked list class
{
public:
    //data members
    Node *start;
    Node *last;
    Node *ploc;
    Node *loc;
    //user defined functions
    SLL();
    bool isEmpty();
    void InsertAtFront(int value);
    void InsertAtEnd(int value);
    void PrintList();
    void Search(int value);
    void InsertSorted(int value);
    void DeleteValue(int value);
    void DeleteList();
};

#endif // SLL_H
