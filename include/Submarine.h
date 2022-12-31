//2043414 Marco Toffoletto
#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Ship.h"

class Submarine : public Ship{
private:

public:
    //Constructor 
    Submarine(): Ship(1,1){}
    //Destructor
    ~Submarine() override = default;

    void action() override;
};

#include "Submarine.hpp"

#endif