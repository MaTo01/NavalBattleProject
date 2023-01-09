//2043414 Marco Toffoletto
#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP

#include "Battleship.h"

/*
The battleship can fire in any position of the grid, 
but it can't move. If the position of the grid where it 
will fire is occupied, the attack grid will be 
marked with X at that position.
Otherwise, the attack grid will be marked with O at that
position.
*/
void Battleship::action(Position pos, DefenseGrid* enemyDefenseGrid){ 
    if(!attackGrid_->isAlreadyMarked(pos)){ 
        if(enemyDefenseGrid->isShipAtPosition(pos)){
            attackGrid_->markHit(pos);
            Ship *ship = enemyDefenseGrid->getShipAtPosition(pos);
            ship->setArmor(ship->getArmor()-1);
            if(ship->isSunk()){
                enemyDefenseGrid->removeShip(ship); 
            } else {
                enemyDefenseGrid->markShipAsHit(pos);
            }
        } else {
            attackGrid_->markMiss(pos);
        }
    }else{
        throw std::invalid_argument("Cell already marked as hit!");
    }
}

#endif
