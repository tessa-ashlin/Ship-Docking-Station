#include "Dock.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, Dock* obj)
{
    if (obj->getMinutes_In() < 10)
    {
        out << "Time In: " << obj->getHour_In() << ":0" << obj->getMinutes_In();
    }
    else
    {
        out << "Time In: " << obj->getHour_In() << ":" << obj->getMinutes_In();
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, Dock obj)
{
    if (obj.Minutes_In < 10)
    {
        out << "Time In: " << obj.Hour_In << ":0" << obj.Minutes_In;
    }
    else
    {
        out << "Time In: " << obj.Hour_In << ":" << obj.Minutes_In;
    }
    return out;
}