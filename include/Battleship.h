//2043414 Marco Toffoletto
#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "Ship.h"

class Battleship : public Ship{
private:
    Grid *grid_;
public:
    //Constructor
    Battleship(Position bow, Position stern, Grid *grid)
        : Ship(5, 5, bow, stern), grid_{grid}{}
    //Destructor
    ~Battleship() override = default;
    
    //Override of the virtual function of Ship
    void action(Position pos) override;  
};

#include "Battleship.hpp"

#endif