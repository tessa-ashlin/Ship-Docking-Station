#ifndef TICKET_H
#define TICKET_H
#include "Ship.h"
#include "Dock.h"

class Ticket
{
    private:

    Ship* Ship_Info = nullptr;
    Dock* Dock_Info = nullptr;
    int Hour_Out = 0;
    int Minutes_Out = 0; 

    public:

    // Friend Classes

    friend class Dock;
    friend class Ship;

    // Constructors
    
    Ticket() {};
    Ticket(Ship* s, Dock* d, int h, int m) {Ship_Info = s, Dock_Info = d, Hour_Out = h, Minutes_Out = m;}

    // Accessors

    Ship* getShipInfo(){return Ship_Info;}
    Dock* getDockInfo() {return Dock_Info;}
    int getHourOut(){return Hour_Out;}
    int getMinutesOut(){return Minutes_Out;}

    // Mutators

    void setShipInfo(Ship* s) {Ship_Info = s;}
    void setDockInfo(Dock* d) {Dock_Info = d;}
    void setHourOut (int h) {Hour_Out = h;}
    void setMinutesOut (int m) {Minutes_Out = m;}

    // Overloaded << Operator

    friend std::ostream& operator<<(std::ostream& out, const Ticket& obj);

    // Method to get fine for ships who stayed too long

    int getFine () const;

};

#endif // TICKET_H