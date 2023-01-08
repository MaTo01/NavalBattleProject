//2043414 Marco Toffoletto
#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Ship.h"
#include "AttackGrid.h"

class Submarine : public Ship{
private:
    AttackGrid *attackGrid_;
    DefenseGrid *defenseGrid_;
public:
    //Constructor 
    Submarine();
    Submarine(Position bow, Position stern, AttackGrid *attackGrid, DefenseGrid *defenseGrid)
        : Ship(1, bow, stern, 'S'), attackGrid_{attackGrid}, defenseGrid_{defenseGrid}{}
    //Destructor
    ~Submarine() override = default;

    //Override of the virtual function of Ship
    void action(Position pos, DefenseGrid * enemyDefenseGrid = nullptr) override; 
};

#include "Submarine.hpp"

#endif
