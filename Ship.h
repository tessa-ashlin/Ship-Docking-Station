#ifndef SHIP_H
#define SHIP_H
#include <string>

class Ship
{
private:
    std::string Name = "";
    std::string Ship_ID = "";
    int Credit = 0;
    Ship* Next = nullptr;

public:

    //Constructors

    /*void*/ Ship(){};
    /*void*/ Ship(std::string n){Name = n;};
    /*void*/ Ship(std::string n, std::string id, int c){Name = n; Ship_ID = id; Credit = c;};

    //Accessors
    
    std::string getName() const {return Name;}
    std::string getShip_ID() const {return Ship_ID;}
    int getCredit() const {return Credit;}
    Ship* getNext() const {return Next;}

    // Mutators

    void setName(std::string n) {Name = n;}
    void setShip_ID(std::string id) {Ship_ID = id;}
    void setCredit(int c) {Credit = c;}
    void setNext(Ship* s) {Next = s;}

    // Overloaded Operators

    friend std::ostream& operator<<(std::ostream&, Ship*);
    friend std::ostream& operator<<(std::ostream&, Ship);

};

#endif // SHIP_H