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
If so, the enemy's ships will be signed into the grid as Y, 
but the player won't know which type of ship it is
*/
void Submarine::action(Position pos){
    if(grid_->isShipAt(pos)){
        break; //can't move there
    }else{
        //TODO: grid member function to update ship position
        for (int i = pos.getX() - 2; i <= pos.getX() + 2; i++) {
            for (int j = pos.getY() - 2; j <= pos.getY() + 2; j++) {
                Ship *ship = grid_->getShipAt(pos);
                if (ship) {
                    grid_->shipFoundAt(pos)
                }
            }
        }
    }

}


#endif
