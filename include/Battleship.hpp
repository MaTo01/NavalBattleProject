//2043414 Marco Toffoletto
#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP

#include "Battleship.h"

/*
The action performed by the battleship is to fire at a certain position on the enemy's defense grid:
first it checks if the position where the action is requested has not already been hit and, if so, fires.
This is possible thanks to the "isShipAtPosition" function which checks if a ship is present in that position,
and marks the shot on the attack grid and enemy's defense grid accordingly.
On the other hand, if the position where the action is requested has already been hit, it throws an exception.
*/
void Battleship::action(Position pos, DefenseGrid* enemyDefenseGrid) { 
    if(!attackGrid_->isAlreadyMarked(pos)) {
        if(enemyDefenseGrid->isShipAtPosition(pos)) {
            attackGrid_->markHit(pos);
            enemyDefenseGrid->markShipAsHit(pos);
        } else {
            attackGrid_->markMiss(pos);
        }
    } else {
        throw std::invalid_argument("Cell already marked as hit.");
    }
}

#endif
