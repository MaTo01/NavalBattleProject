//2043414 Marco Toffoletto
#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Ship.h"

class Submarine : public Ship{
private:
    Grid *grid_;
public:
    //Constructor 
    Submarine(Position bow, Position stern, Grid *grid)
        : Ship(1, 1, bow, stern), grid_{grid}{}
    //Destructor
    ~Submarine() override = default;

    //Override of the virtual function of Ship
    void action(Position pos) override;
};

#include "Submarine.hpp"

#endif