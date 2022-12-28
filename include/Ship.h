#ifndef SHIP_H
#define SHIP_H

class Ship{
protected:
    int size;
    int armor;
    
public:
    Ship() = default; 
    virtual ~Ship() = 0;
    virtual void action() = 0;
};

Ship::~Ship(){}

#endif