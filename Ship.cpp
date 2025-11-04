#include "Ship.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, Ship* obj)
{
    out << "Ship ID: " << obj->Ship_ID << std::endl << "Name: " << obj->Name;
    return out;
}

std::ostream& operator<<(std::ostream& out, Ship obj)
{
    out << "Ship ID: " << obj.Ship_ID << std::endl << "Name: " << obj.Name;
    return out;
}