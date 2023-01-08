//2043414 Marco Toffoletto
#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Ship.h"

class Submarine : public Ship{
private:
    AttackGrid *attackGrid_;
    DefenseGrid *defenseGrid_;
public:
    //Constructor 
    Submarine(Position bow, Position stern, attackGrid *attackGrid, defenseGrid *defenseGrid)
        : Ship(1, 1, bow, stern), attackGrid_{attackGrid}, defenseGrid_{defenseGrid}{}
    //Destructor
    ~Submarine() override = default;

    //Override of the virtual function of Ship
    void action(Position pos, DefenseGrid *defenseGrid = NULL) override;
};

#include "Submarine.hpp"

#endif