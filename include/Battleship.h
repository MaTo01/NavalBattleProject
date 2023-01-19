//2043414 Marco Toffoletto
#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "Ship.h"
#include "AttackGrid.h"

//Ship's subclass 
class Battleship : public Ship {
private:
    //Pointer to the player's attack grid, used to mark the action of the battleship
    AttackGrid *attackGrid_;
public:
    //Constructor
    Battleship(Position bow, Position stern, AttackGrid *attackGrid)
        : Ship(5, bow, stern, 'C'), attackGrid_{attackGrid} {}
    //Destructor override
    ~Battleship() override = default;

    //Ship's virtual function override
    void action(Position pos, DefenseGrid * enemyDefenseGrid = nullptr) override;  
};

#include "Battleship.hpp"

#endif
