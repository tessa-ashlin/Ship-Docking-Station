// Program that defines a linked list class

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Ship.h"

class LinkedList
{
    private:

    // Set the first node to point at nothing

    Ship* Head = nullptr;

    public:

    // Constructors

    LinkedList() {};
    LinkedList(Ship* s) {Head = s;}

    // Destructor

    ~LinkedList();

    // Mutators

    void setHead(Ship s){Head = &s;}

    // Overloaded Operators

    Ship* operator-- ();
    void operator+= (Ship*);
};

#endif // LINKEDLIST_H