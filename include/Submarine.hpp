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
void Submarine::action(Position pos, Grid *enemyDefenseGrid){
    //TODO: DefenseGrid function to check if there is a ship at that position 
    if(defenseGrid_->isShip(pos)){
        break; //can't move there, stop the action
    }else{
        defenseGrid_->moveShip(pos); //TODO: DefenseGrid member function to update ship position
        for (int i = pos.getX() - 2; i <= pos.getX() + 2; i++) {
            for (int j = pos.getY() - 2; j <= pos.getY() + 2; j++) {
                Ship *ship = enemyDefenseGrid->getShip(pos); //TODO: DefenseGrid function to get the type of ship at that position 
                if (ship) {
                    attackGrid_->markScan(Position(i,j));
                }
            }
        }
    }

}


#endif