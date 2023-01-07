//2043414 Marco Toffoletto
#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP

#include "Battleship.h"

/*
The battleship can fire in any position of the grid, 
but it can't move. If the position of the grid where it 
will fire is occupied, the attack grid will be 
marked with a X at that position using "shipHittedAt(Position pos)"
Otherwise, the attack grid will be marked with a O at that
position using "shipMissedAt(Position pos)"
*/
void Battleship::action(Position pos){
    if(grid_->isShipAt(pos)){
        grid_->shipHitAt(pos);
        Ship *ship = grid_->getShipAt(pos);
        ship->setArmor(ship->getArmor()-1);
        if(ship->isSunk()){
            ship->eraseShip();
        }
    }else{
        grid_->shipMissedAt(pos);
    }
}

#endif
