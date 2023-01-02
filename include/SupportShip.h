//2043414 Marco Toffoletto
#ifndef SUPPORTSHIP_H
#define SUPPORTSHIP_H

#include "Ship.h"

class SupportShip : public Ship{
private:
    Grid *grid_;
public:
    //Constructor
    SupportShip(Position bow, Position stern, Grid *grid)
        : Ship(3, 3, bow, stern), grid_{grid}{}
    //Destructor
    ~SupportShip() override = default;

    //Override of the virtual function of Ship
    void action(Position pos) override;
};

#include "SupportShip.hpp"

#endif