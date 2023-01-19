//2043414 Marco Toffoletto
#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Ship.h"
#include "AttackGrid.h"

//Ship's subclass 
class Submarine : public Ship {
private:
    //Pointer to the player's attack grid and defense grid, used to mark 
    //the submarine sonar readings and to move the submarine respectively
    AttackGrid *attackGrid_;
    DefenseGrid *defenseGrid_;
public:
    //Constructor
    Submarine(Position bow, Position stern, AttackGrid *attackGrid, DefenseGrid *defenseGrid)
        : Ship(1, bow, stern, 'E'), attackGrid_{attackGrid}, defenseGrid_{defenseGrid} {}
    //Destructor override
    ~Submarine() override = default;

    //Ship's virtual function override
    void action(Position pos, DefenseGrid * enemyDefenseGrid = nullptr) override; 
};

#include "Submarine.hpp"

#endif
