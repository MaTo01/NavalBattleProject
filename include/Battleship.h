//2043414 Marco Toffoletto
#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "Ship.h"

class Battleship : public Ship{
private:
    AttackGrid *attackGrid_;
    DefenseGrid *defenseGrid_;
public:
    //Constructor
    Battleship(Position bow, Position stern, AttackGrid *attackGrid, DefenseGrid *defenseGrid)
        : Ship(5, 5, bow, stern), attackGrid_{attackGrid}, defenseGrid_{defenseGrid}{}
    //Destructor
    ~Battleship() override = default;
    
    //Override of the virtual function of Ship
    void action(Position pos, DefenseGrid *enemyDefenseGrid = NULL) override;  
};

#include "Battleship.hpp"

#endif