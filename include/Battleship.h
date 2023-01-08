//2043414 Marco Toffoletto
#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "Ship.h"
#include "AttackGrid.h"
#include "DefenseGrid.h"

class Battleship : public Ship{
private:
    AttackGrid *attackGrid_;
public:
    //Constructor
    Battleship(Position bow, Position stern, AttackGrid *attackGrid)
        : Ship(5, bow, stern, 'B'), attackGrid_{attackGrid} {}
    //Destructor
    ~Battleship() override = default;
    
    //Override of the virtual function of Ship
    void action(Position pos, DefenseGrid *enemyDefenseGrid = NULL) override;  
};

#include "Battleship.hpp"

#endif
