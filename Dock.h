#ifndef DOCK_H
#define DOCK_H
#include "Ship.h"

class Dock
{
private:

    int Hour_In = 0;
    int Minutes_In = 0;
    Ship* Mooring = nullptr;

public:
    //Constructors

    /*void*/ Dock() {};
    /*void*/ Dock(int h, int m, Ship* s) {Mooring = s; Minutes_In = m; Hour_In = h;}

    //Accessors

    int getMinutes_In() {return Minutes_In;}
    int getHour_In() {return Hour_In;}
    Ship* getMooring() {return Mooring;}

    //Mutators
    
    void setMooring (Ship* s){Mooring = s;}
    void setMinutes_In(int m){Minutes_In = m;}
    void setHour_In(int h){Hour_In = h;}

    //Overloaded Operators
    
    friend std::ostream& operator<<(std::ostream&, Dock*);
    friend std::ostream& operator<<(std::ostream&, Dock);

};

#endif // DOCK_H