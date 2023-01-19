//2043414 Marco Toffoletto
#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP

#include "Battleship.h"

/*
The action performed by the battleship is to fire at a certain position on the enemy's defense grid:
The battleship fires even if a position has already been hit. this must be done because an enemy support ship
could heal a ship that has already been hit, if there was a check I could no longer sink the first hit and then healed ship.
This is possible thanks to the "isShipAtPosition" function which checks if a ship is present in that position,
and marks the shot on the attack grid and enemy's defense grid accordingly.
*/

void Battleship::action(Position pos, DefenseGrid* enemyDefenseGrid) { 
    if(enemyDefenseGrid->isShipAtPosition(pos)) {
        attackGrid_->markHit(pos);
        enemyDefenseGrid->markShipAsHit(pos);
    } else {
        attackGrid_->markMiss(pos);
    }
}

#endif
