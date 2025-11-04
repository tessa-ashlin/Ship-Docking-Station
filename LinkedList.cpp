#include "LinkedList.h"
#include <iostream>

// Overloaded += operator, adds ship to the end of the list/queue

void LinkedList::operator+= (Ship* obj)
{
    // If head points at nothing, change head to the node given by the user

    Ship* newShip = new Ship(*obj);

    if (Head == nullptr)
    {
        Head = newShip;
        newShip->setNext(nullptr);
    }
    else

    // Set the last node's next object to null
    
    {
        Ship* cur = Head;
        while (cur->getNext() != nullptr)
        {
            cur = cur->getNext();
        }

        cur->setNext(newShip);
        obj->setNext(nullptr);
    }

    // Debug statement

    /*

    std::cout << "\nHead is currently: " << Head << "\n";
    Ship* cur = Head;
    while (cur->getNext() != nullptr) {
        std::cout << "Next in line is: " << cur->getNext() << std::endl;
        cur = cur->getNext();
    }
    std::cout << "\n\n";

    */

}

// Overloaded -- operator, removes ship from beginning of list/queue

Ship* LinkedList::operator-- ()
{
    Ship* hold = Head;
    Head = Head->getNext();

    return hold;
}

// Destructor

LinkedList::~LinkedList()
{
    Ship* cur = Head;
    while (cur != nullptr)
    {
        Ship* next = cur->getNext();
        delete cur;
        cur = next;
    }
}