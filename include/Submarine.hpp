//2043414 Marco Toffoletto
#ifndef SUBMARINE_HPP
#define SUBMARINE_HPP

#include "Submarine.h"

/*
The submarine can't fire, but it can move freely into
the grid; the only limitation is that it can't go in a 
position that is already occupied.
After moving, the submarine shows a matrix of 5*5 
around it, so the player can see if into that window
there are any enemy's ships.
If so, the enemy's ship will be signed into the grid as Y, 
but the player won't know which type of ship it is
*/
void Submarine::action(Position pos, DefenseGrid* enemyDefenseGrid){
    if(!defenseGrid_->isShipAtPosition(pos)){
        defenseGrid_->moveShip(this,pos);
        Ship *ship = enemyDefenseGrid->getShipByPosition(pos);
        for (int i = pos.getX() - 2; i <= pos.getX() + 2; i++) {
            for (int j = pos.getY() - 2; j <= pos.getY() + 2; j++) { 
                if (ship) {
                    attackGrid_->markScan(Position(i, j));
                }
            }
        }
    }else{
        throw std::invalid_argument("Cell position already occupied!");
    }
}

#endif
