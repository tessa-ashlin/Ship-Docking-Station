#include "Ticket.h"
#include <iostream>

// Function to print all of the items in Ticket

std::ostream& operator<<(std::ostream& out, const Ticket& obj)
{
    out << obj.Ship_Info << std::endl;
    out << obj.Dock_Info << std::endl;

    // If they stayed for under 10 minutes, print a 0 before the number

    if (obj.Minutes_Out < 10)
    {
        out << "Time Out: " << obj.Hour_Out << ":0"  << obj.Minutes_Out << std::endl;
    }
    else
    {
    out << "Time Out: " << obj.Hour_Out << ":"  << obj.Minutes_Out << std::endl;
    }

    out << "Credited Minutes: " << obj.Ship_Info->getCredit() << std::endl;

    // Figure out how many extra minutes were taken

    int timeMins = /*Time in*/ ((obj.Dock_Info->getHour_In() * 60) + obj.Dock_Info->getMinutes_In())
             - /*Time out*/ ((obj.Hour_Out * 60) + obj.Minutes_Out);

    // If time in minutes is negative, make it positive

    if (timeMins < 0)
    {
        timeMins *= -1;
    }

    timeMins -= obj.Ship_Info->getCredit();

    
    out << "Extra Minutes: " << timeMins << std::endl;
    out << "Fine: " << obj.getFine() << " units";

    return out;
}

// Function to calculate fines for overstaying ships

int Ticket::getFine () const
{
    int timeMins = /*Time in*/ ((Dock_Info->getHour_In() * 60) + Dock_Info->getMinutes_In())
                 - /*Time out*/ ((Hour_Out * 60) + Minutes_Out);

    // If time in minutes is negative, make it positive

    if (timeMins < 0)
    {
        timeMins *= -1;
    }
    
    // Subtract paid time from the final time

    timeMins -= Ship_Info->getCredit();

    int fine = 0;

    if (timeMins > 60)
    {
        fine = 12000 + ((timeMins - 60) * 500);
    }
    else
        fine = timeMins * 200;

    return fine;
}